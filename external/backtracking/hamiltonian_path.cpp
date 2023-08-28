#include <bits/stdc++.h> 
using namespace std;

bool issafe(vector<vector<int>> &adj,int path[],int ind,int node,int n){
    for(int i=1;i<ind;i++){
        if(path[i]==node || adj[ind-1][node]==1e9) return false; //no edge between previous node and current node
        if(ind==n && adj[node][path[1]]==1e9) return false;
    }
    return true;
}

void h(vector<vector<int>> &adj,int path[],int ind,int n){
    if(ind==n+1){
        for(int i=1;i<=n;i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    } 
    for(int i=2;i<=n;i++){
        if(issafe(adj,path,ind,i,n)==true){
            path[ind]=i;
            h(adj,path,ind+1,n);
        }
    }
}



int main()
{   int n,e;
   cin>>n>>e;
   vector<vector<int>> adj(n+1,vector<int>(n+1,1e9));
   for(int i=0;i<e;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u][v]=w;
    adj[v][u]=w;
   }
int path[n+1];
  path[0]=0;
  path[1]=1;//fixing the node;
   h(adj,path,2,n);
   return 0;
}

/*
6
8
1 2 1
2 3 1
2 5 1
3 4 1
4 5 1
3 6 1
5 6 1
6 1 1
1 2 3 4 5 6 
1 2 5 4 3 6
1 6 3 4 5 2
1 6 5 4 3 2


*/