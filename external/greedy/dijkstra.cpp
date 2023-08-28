#include<bits/stdc++.h>
using namespace std;




//dijkstra's algorithm
//single source shortest path  

void dj(vector<pair<int,int>> adj[],int start,int n){
   vector<int> dis(n,1e9);
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
   dis[start]=0;
   pq.push({0,start});
   while(!pq.empty()){
    int w=pq.top().first;
    int u=pq.top().second; 
    pq.pop();

    for(auto it:adj[u]){
        int v=it.first;
        int wt=it.second;
        int d=w+wt;
        if(d<dis[v]){
            dis[v]=d;
            pq.push({d,v});
        }
    } 

   } 

   for(int i=0;i<n;i++){
    cout<<dis[i]<<" ";
   }



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
   dj(adj,0,n);
    
 
  }

    /*
    6 8
0 1 3
0 5 4
5 4 3
5 2 5
4 1 2
4 3 4
3 2 6
2 1 4

0 3 7 9 5 4 
    
    */
