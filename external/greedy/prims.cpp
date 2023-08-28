#include<bits/stdc++.h>
using namespace std;




//prims -minimum spanning tree


int  prims_pq(vector<pair<int,int>> adj[],int start,int n){
   vector<int> vis(n+1,0);
   int sum=0;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   pq.push({0,start});
   while(!pq.empty()){
    int d=pq.top().first;
    int u=pq.top().second; 
    pq.pop();
    if(vis[u]!=1) {
        sum+=d;
    }
    vis[u]=1;

    for(auto it:adj[u]){
        if(vis[it.first]==0){
            pq.push({it.second,it.first});
        }
    }
   } 
   return sum;



}

int  prims(vector<pair<int,int>> adj[],int start,int n){
   vector<int> vis(n+1,0);
   int sum=0;
  // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   vis[start]=1;
   for(int l=0;l<n-1;l++){ 
    int mini=INT_MAX,s,d;
    for(int i=0;i<=n;i++){
        if(vis[i]==1){
            for(auto it:adj[i]){
                if(vis[it.first]==0){
                    if(mini>it.second){
                        mini=it.second;
                        s=i;
                        d=it.first;

                    }
                }
            }
        }
    } 
    vis[d]=1;
    cout<<s<<" "<<d<<endl;
    sum+=mini;

   }
  
return sum;


}




int main(){ 
    int n,e;
    cin>>n>>e;
  vector<pair<int,int>> adj[n+1];
  for(int i=0;i<e;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
    }
  cout<<prims(adj,1,n)<<endl;
 cout<<prims_pq(adj,1,n);
    
 
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

    
