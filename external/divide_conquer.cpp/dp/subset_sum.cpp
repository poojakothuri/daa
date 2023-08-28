#include<bits/stdc++.h>
using namespace std;

//subset sum  possible or not

bool tab(vector<vector<int>> &tb,int val[],int sum,int n){
    for(int j=0;j<=sum;j++){
        if(val[0]==j) tb[0][j]=1; 
        else
            tb[0][j]=0;
    } 

    for(int ind=1;ind<n;ind++){ 
        for(int s=0;s<=sum;s++){
            if(s==0){
                tb[ind][s]=1;

            }
            else{
                int np=tb[ind-1][s];
                int p=0;
                if(val[ind]<=s){
                    p=tb[ind-1][s-val[ind]];
                }
                tb[ind][s]=(np||p);
            }
        }
    } 
    return tb[n-1][sum];
}


bool subset(vector<vector<int>> &dp,int val[],int sum,int ind){
    if(sum==0 ) return true;
    if(ind==0){
        if(val[0]==sum) return true;
        return false;
    }
  if(dp[ind][sum]!=-1) return dp[ind][sum];
    int np=subset(dp,val,sum,ind-1);
    int p=0;
    if(val[ind]<=sum){
        p=subset(dp,val,sum-val[ind],ind-1);

    }
    return dp[ind][sum]=(np||p);
}


int main(){
    int n,sum;cin>>n>>sum;
  int val[n];

    for(int i=0;i<n;i++) cin>>val[i];
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
   cout<<subset(dp,val,sum,n-1)<<endl; 
   vector<vector<int>> tb(n,vector<int>(sum+1));
   cout<<tab(tb,val,sum,n)<<endl; 
   for(int i=0;i<n;i++){
    for(int j=0;j<=sum;j++){
        cout<<tb[i][j]<<" ";
    }
    cout<<endl;
   }
}

/*

6 9
3 34 4 12 5 2


*/
