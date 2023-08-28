#include<bits/stdc++.h>
using namespace std;


//optimal binary search tree -obst
//arranging bst in such a way that 
//element with highest frequency are searched in less operations 


int fs(int f[],int i,int j){ 
    int s=0;
    for(int k=i;k<=j;k++){
        s+=f[k];
    }
    return s;
} 
int tab(vector<vector<int>> &tb,int f[],int n){
   
   for(int l=0;l<n;l++){
    for(int i=0;i<n-l;i++){
        int j=i+l;
        if(i==j) tb[i][j]=f[i]; 
        else if(i>j) tb[i][j]=0;
        else{
            int mini=INT_MAX;
            for(int k=i;k<=j;k++){
                int val=((i>k-1)?0:tb[i][k-1])+((k+1>j)?0:tb[k+1][j]);
                mini=min(mini,val);
            }  
            int fsum=fs(f,i,j);
            tb[i][j]=mini+fsum;
        }
    }
   } 
   return tb[0][n-1];
}

int obst( vector<vector<int>> &dp,int f[],int i,int j){
    if(i==j)
        return f[i]; //single node 
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<=j;k++){ //making each element as a root
            int val=obst(dp,f,i,k-1)+obst(dp,f,k+1,j);
            mini=min(val,mini);
        } 
        int fsum=fs(f,i,j);
      return  dp[i][j]=mini+fsum; 
}

int main(){ 
    int n;//
    cin>>n;
    int f[n]; //frequency array
    for(int i=0;i<n;i++) cin>>f[i];
    vector<vector<int>> dp(n,vector<int>(n,-1));
     vector<vector<int>> tb(n,vector<int>(n));
     cout<<obst(dp,f,0,n-1)<<endl;
    cout<<tab(tb,f,n)<<endl; 
 }

/*
3
15 20 8
66
66

5
10 15 20 25 30

205
*/
