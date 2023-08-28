#include<bits/stdc++.h>
using namespace std;


class dsu{
    vector<int> size,parent;
public:
    dsu(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) parent[i]=i;

    }

   int findUltimateParent(int node){
    if(node==parent[node]) return node;
     return parent[node]=findUltimateParent(parent[node]);
   }

  void unionBySize(int u,int v){
    int pu=findUltimateParent(u);
    int pv=findUltimateParent(v);
    if(pu==pv) return;
    if(size[pu]<size[pv]){
        parent[pu]=pv;
        size[pv]+=size[pu];
    }
    else if(size[pv]<=size[pu]){
        parent[pv]=pu;
        size[pu]+=size[pv];
    }
  } 
};



int main(){ 
    int n,e;
    cin>>n>>e;
  vector<pair<int,pair<int,int>>> edgewt;
  for(int i=0;i<e;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edgewt.push_back({w,{u,v}});
  }
  int sum=0;
  dsu ds(n);
  sort(edgewt.begin(),edgewt.end());
  for(int i=0;i<=n;i++){
    int w=edgewt[i].first;
    int u=edgewt[i].second.first;
    int v=edgewt[i].second.second;
    int pu=ds.findUltimateParent(u);
    int pv=ds.findUltimateParent(v);
    if(pu==pv) continue;
    else{
        ds.unionBySize(u,v);
        cout<<u<<" "<<v<<endl;
        sum+=w;
    }
  }
  cout<<sum<<endl;

    
 
  }

/*
6 9
1 5 4
1 2 2
1 4 1
2 6 7
2 3 3
2 4 3
3 6 8
3 4 5
4 5 9
1 4
1 2
2 3
1 5
2 6
17


*/
