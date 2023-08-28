#include<bits/stdc++.h>
using namespace std;

//floyd warshall algo -all pair shortest paths 



void f(vector<vector<int>> &adj,int n){
    for(int via=0;via<=n;via++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){ 
                if(adj[i][via]==1e9 || adj[via][j]==1e9) continue;
                else
                adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
            }
        }
    }
}


void floyd(vector<vector<int>> &adj,int n){
    for(int via=0;via<=n;via++){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
            }
        }
    }
}

int main(){ 
    int n,e;//
    cin>>n>>e;
   vector<vector<int>> adj(n+1,vector<int>(n+1,1e9));
   for(int i=0;i<e;i++){
    int u,v,w;
    cin>>u>>v>>w;
    adj[u][v]=w; //directed graph
   } 
   for(int i=0;i<=n;i++){
     adj[i][i]=0;
   }
floyd(adj,n); 

for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                cout<<((adj[i][j]>=1e9)?-1:adj[i][j])<<" ";
            cout<<endl;
        } 


f(adj,n);
 
 for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                cout<<((adj[i][j]>=1e9)?-1:adj[i][j])<<" ";
            cout<<endl;
        }
    
    
 }
    


    
    
 
 /*
 6 9
1 2 1
2 4 2
4 6 1
1 3 5
2 5 1
2 3 2
3 5 2
4 5 3
5 6 2 

0 -1 -1 -1 -1 -1 -1 
-1 0 1 3 3 2 4 
-1 -1 0 2 2 1 3 
-1 -1 -1 0 -1 2 4 
-1 -1 -1 -1 0 3 1 
-1 -1 -1 -1 -1 0 2 
-1 -1 -1 -1 -1 -1 0 

 
 
 */

    
