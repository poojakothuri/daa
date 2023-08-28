#include<bits/stdc++.h>
using namespace std;


//binomial coefficient 
//(n,r)=(n-1,r-1)+(n-1,r)

int tab(int n,int r,vector<vector<int>> &tb){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=r;j++){
            if(i==j || j==0){
                tb[i][j]=1;
            }
            else if(j>i){
                tb[i][j]=0;
            }
            else{
                tb[i][j]=tb[i-1][j-1]+tb[i-1][j];
            }
        }
    } 
    return tb[n][r];
}

int bc(int n,int r, vector<vector<int>> &dp){
    if(n==r ||r==0) return 1; 
    if(dp[n][r]!=-1) return dp[n][r];
    return dp[n][r]=bc(n-1,r-1,dp)+bc(n-1,r,dp);
}

int main(){ 
    int n,r;
    cin>>n>>r;
    if(n<r) {
        cout<<-1<<endl;
    }else{
    vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
     vector<vector<int>> tb(n+1,vector<int>(r+1));
     cout<<bc(n, r,dp)<<endl;
     cout<<tab(n,r,tb)<<endl; 
 }

    
}