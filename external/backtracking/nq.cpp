#include<bits/stdc++.h>
using namespace std;



bool issafe(int ans[],int ind,int col){
    for(int i=1;i<ind;i++){
        if(ans[i]==col || abs(ind-i)==abs(col-ans[i])) return false;
    } 
    return true;
}

void nq(int ans[],int ind,int n){
     if(ind==n+1){
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
            
        }
        cout<<endl;
        return;
     } 

     for(int i=1;i<=n;i++){
        if(issafe(ans,ind,i)){
            ans[ind]=i;
            nq(ans,ind+1,n);
        }
     }
}


int main(){ 
    int n;
    cin>>n;
    int a[n+1];
    a[0]=0;
    nq(a,1,n);


    
 
  }

    
