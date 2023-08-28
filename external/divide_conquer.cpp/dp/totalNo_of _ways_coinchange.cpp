#include<bits/stdc++.h>
using namespace std;

//total no. of ways to make given sum

int tab(vector<vector<int>> &tb,int val[],int sum,int n){

    for(int j=0;j<=sum;j++){
       if(j%val[0]==0) tb[0][j]=1;
       else
        tb[0][j]=0;
    } 


    for(int ind=1;ind<n;ind++){
        for(int s=0;s<=sum;s++){
            if(s==0){ //possible to make sum
                tb[ind][s]=1;
            }
            else{
                int np=tb[ind-1][s];
                int p=0;
                if(val[ind]<=s){
                    p=tb[ind][s-val[ind]];
                }
                tb[ind][s]=np+p;
            }
        }
    } 
    return tb[n-1][sum];
}
  
int coin(vector<vector<int>> &dp,int val[],int sum,int ind){ 
    if(sum==0) return 1; //if(sum==0) then it is possible way to make  given sum 
      if(ind==0){
        if(sum%val[0]==0) return 1;
        return 0; //not possible to make given sum
      }  
 
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    int np=coin(dp,val,sum,ind-1);
    int p=0;
    if(val[ind]<=sum){
        p=coin(dp,val,sum-val[ind],ind);
    }

    return dp[ind][sum]=np+p;
} 


int main(){
    int n,sum;cin>>n>>sum;
  int val[n];

    for(int i=0;i<n;i++) cin>>val[i];
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
   cout<<coin(dp,val,sum,n-1)<<endl; 
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

3 6
1 2 3 


7
7
1 1 1 1 1 1 1 
1 1 2 2 3 3 4 
1 1 2 3 4 5 7 


*/
