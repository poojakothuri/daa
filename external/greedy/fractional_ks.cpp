#include<bits/stdc++.h>
using namespace std;

//fractional knapsack
//maximize the value of the bag of weight w
//sorting according  value per unit weight in descending order

void sortd(int wt[],int val[],int n){
    for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){ 
        double v1=(double)(val[j]/(wt[j]*1.0));
         double v2=(double)(val[j+1]/(wt[j+1]*1.0));
        if(v1<v2){
            swap(wt[j],wt[j+1]);
            swap(val[j],val[j+1]);
        }
    }
    }
}


int main(){ 
    int n,w;
    cin>>n>>w; 
    int wt[n],val[n];
    for(int i=0;i<n;i++) cin>>wt[i];
    for(int i=0;i<n;i++) cin>>val[i]; 
    sortd(wt,val,n);
    double ans=0;
    for(int i=0;i<n;i++){
        if(wt[i]<=w){
              ans+=val[i]; 
              w-=wt[i];
               
              }
        else {
            ans+=(double)(val[i]/(wt[i]*1.0))*w;
            w=0;
        }
    } 
    
    cout<<ans<<endl;
 }

/*
5 6
5 4 2 3 16
20 40 15 9 35


55

*/
    
