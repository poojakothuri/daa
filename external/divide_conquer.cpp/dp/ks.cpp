#include<bits/stdc++.h>
using namespace std;

//0/1 knapsack

int tab(vector<vector<int>> &tb,int wt[],int val[],int W,int n){

    for(int j=0;j<=W;j++){
        if(wt[0]<=j) tb[0][j]=val[0];
        else 
        tb[0][j]=0;
    } 


    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=W;w++){
            if(w==0){
                tb[ind][w]=0;
            }
            else{
                int np=tb[ind-1][w];
                int p=INT_MIN;
                if(wt[ind]<=w){
                    p=val[ind]+tb[ind-1][w-wt[ind]];
                }
                tb[ind][w]=max(np,p);
            }
        }
    } 
    return tb[n-1][W];
}

int ks_dp(vector<vector<int>> &dp,int wt[],int val[],int w,int ind){ 
    if(w==0) return 0;
      if(ind==0){
        if(wt[0]<=w) return val[0];
        return 0;
      }
 
    if(dp[ind][w]!=-1) return dp[ind][w];
    int np=ks_dp(dp,wt,val,w,ind-1);
    int p=INT_MIN;
    if(wt[ind]<=w){
        p=val[ind]+ks_dp(dp,wt,val,w-wt[ind],ind-1);
    }

    return dp[ind][w]=max(p,np);
}


int main(){
    int n,w;cin>>n>>w;
   int wt[n],val[n];
   for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>val[i];
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
   cout<<ks_dp(dp,wt,val,w,n-1)<<endl; 
   vector<vector<int>> tb(n,vector<int>(w+1));
   cout<<tab(tb,wt,val,w,n)<<endl;
}

/* 

5 7
5 3 1 4 6
28 15 16 28 30
46
46

*/