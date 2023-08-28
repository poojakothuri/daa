#include<bits/stdc++.h>
using namespace std;
//matrix chain multiplication -mcm
int tab(vector<vector<int>> &tb,int a[],int n){  
   for(int l=0;l<n;l++){
    for(int i=1;i<=n-l;i++){
        int j=i+l;
        if(i==j) tb[i][j]=0;
        else{
            int mini=INT_MAX;
            for(int k=i;k<j;k++){
                int val=tb[i][k]+tb[k+1][j]+a[i-1]*a[k]*a[j];
                mini=min(mini,val);
            } 
            tb[i][j]=mini;
        }
    }
   } 
   return tb[1][n];
}
int mcm( vector<vector<int>> &dp,int a[],int i,int j){
    if(i==j)
        return 0; //for single matrix 0 operations
    if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int val=mcm(dp,a,i,k)+mcm(dp,a,k+1,j)+a[i-1]*a[k]*a[j]; 
            mini=min(val,mini);
        } 
      return  dp[i][j]=mini; 
}
int main(){ 
    int n;//no. of matrices
    cin>>n;
    int a[n+1];
    for(int i=0;i<n+1;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
     vector<vector<int>> tb(n+1,vector<int>(n+1));
     cout<<mcm(dp,a,1,n)<<endl;
     cout<<tab(tb,a,n)<<endl; 
 }
/*
4
1 2 3 2 4
20
*/
