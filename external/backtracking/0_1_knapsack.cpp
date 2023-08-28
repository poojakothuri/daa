#include <bits/stdc++.h> 
using namespace std;

vector<int> ss;
void printv(int wt[],int val[],int ans[],int n,int w,int &maxi){ 
    int v=0;
    vector<int> d;
       for(int i=1;i<=n;i++){
          if(ans[i]==1){
            d.push_back(wt[i]);
            w-=wt[i];
            v+=val[i];
          }
       } 
       
       if(w>=0){ 
             if(maxi<v){
                ss=d;
                maxi=v;
             }

        }  
        
    
      
}


void ks(int wt[],int val[],int ans[],int ind,int n,int w,int &maxi){
   if(ind==n+1) {
      printv(wt,val,ans,n,w,maxi);
     return;
   } 
   for(int i=0;i<=1;i++){
       ans[ind]=i;
       ks(wt,val,ans,ind+1,n,w,maxi);
   }
}


 
int main()
{   int n,w;
   cin>>n>>w;
   int wt[n+1]; 
   int val[n+1];
   wt[0]=val[0]=0;
   int maxi=0;
   for(int i=1;i<=n;i++) cin>>wt[i];
   for(int i=1;i<=n;i++) cin>>val[i];

 
 int ans[n+1];
   ans[0]=0;
  ks(wt,val,ans,1,n,w,maxi); 
  for(auto it:ss){
    cout<<it<<" ";
  }
  cout<<endl<<maxi<<endl;
   return 0;
}

/*
5
10
5 3 2 4 6
28 15 16 28 30
3 2 4 
59


*/

