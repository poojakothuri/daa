#include<bits/stdc++.h>
using namespace std;

//total number of subsets with given sum



int tab(vector<vector<int>> &tb,int val[],int sum,int n){
    for(int j=0;j<=sum;j++){
       if(j==0 && val[0]==0) tb[0][j]=2;
       else if(val[0]==j || j==0) tb[0][j]=1;
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
                tb[ind][s]=(np+p);
            }
        }
    } 
    return tb[n-1][sum];
}


int subset(vector<vector<int>> &dp,int val[],int sum,int ind){
   
    if(ind==0){
       if(val[0]==0 && sum==0) return 2;//2 subsets with sum as 0 
       if(sum==0 || val[0]==sum) return 1;
       return 0;
    }
  if(dp[ind][sum]!=-1) return dp[ind][sum];
    int np=subset(dp,val,sum,ind-1);
    int p=0;
    if(val[ind]<=sum){
        p=subset(dp,val,sum-val[ind],ind-1);

    }
    return dp[ind][sum]=np+p;
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

5  6
0 2 3 4 5

2
2
2 0 0 0 0 0 0 
1 0 2 0 0 0 0 
1 0 2 1 0 2 0 
1 0 2 1 1 2 2 
1 0 2 1 1 3 2 



*/
