#include<bits/stdc++.h>
using namespace std;



void b(int ans[],int size,int ind){
    if(ind==size+1){
        for(int i=1;i<=size;i++)
         cout<<ans[i]<<" ";
    cout<<endl;
    return; 
    }

    for(int i=0;i<=1;i++){
        ans[ind]=i;
        b(ans,size,ind+1);
    }
}



int main(){
    int n;
    cin>>n;
    int size=ceil(log2(100));
  //  cout<<size; 
     int ans[size+1];
     ans[0]=0;
    b(ans,size,1);

}