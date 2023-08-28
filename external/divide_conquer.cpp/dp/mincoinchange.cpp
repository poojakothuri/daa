#include<bits/stdc++.h>
using namespace std;

//min no. of coins coins needed to make given sum and each coin can be taken any number of times
//V = 30, M = 3, coins[] = {25, 10, 5}
//Output: 2

int tab(vector<vector<int>> &tb,int val[],int sum,int n){

    for(int j=0;j<=sum;j++){
       if(j%val[0]==0) tb[0][j]=j/val[0];
       else
        tb[0][j]=1e9;
    } 


    for(int ind=1;ind<n;ind++){
        for(int s=0;s<=sum;s++){
            if(s==0){
                tb[ind][s]=0;
            }
            else{
                int np=tb[ind-1][s];
                int p=1e9;
                if(val[ind]<=s){
                    p=1+tb[ind][s-val[ind]];
                }
                tb[ind][s]=min(np,p);
            }
        }
    } 
    return tb[n-1][sum];
}

int mincoin(vector<vector<int>> &dp,int val[],int sum,int ind){ 
    if(sum==0) return 0;
      if(ind==0){
        if(sum%val[0]==0) return sum/val[0];
        return 1e9; //not possible to make given sum
      }
 
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    int np=mincoin(dp,val,sum,ind-1);
    int p=1e9;
    if(val[ind]<=sum){
        p=1+mincoin(dp,val,sum-val[ind],ind);
    }

    return dp[ind][sum]=min(p,np);
}


int main(){
    int n,sum;cin>>n>>sum;
  int val[n];

    for(int i=0;i<n;i++) cin>>val[i];
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
   cout<<((mincoin(dp,val,sum,n-1)>=1e9)?-1:mincoin(dp,val,sum,n-1))<<endl; 
   vector<vector<int>> tb(n,vector<int>(sum+1));
   cout<<((tab(tb,val,sum,n)>=1e9)?-1:tab(tb,val,sum,n))<<endl; 
   for(int i=0;i<n;i++){
    for(int j=0;j<=sum;j++){
        cout<<tb[i][j]<<" ";
    }
    cout<<endl;
   }
}

/*

3 5
1 2 3

*/
