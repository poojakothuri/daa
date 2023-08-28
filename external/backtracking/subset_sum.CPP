#include <bits/stdc++.h> 
using namespace std;

void printv(int a[],int ans[],int n,int sum){
       for(int i=1;i<=n;i++){
          if(ans[i]==1){
            sum-=a[i];
          }
       }
       if(sum==0){
        for(int i=1;i<=n;i++){
            if(ans[i]==1) cout<<a[i]<<" ";
        }
         cout<<endl;
       } 
       return ;
}


void ss(int a[],int ans[],int ind,int n,int sum){
   if(ind==n+1) {
      printv(a,ans,n,sum);
     return;
   } 
   for(int i=0;i<=1;i++){
       ans[ind]=i;
       ss(a,ans,ind+1,n,sum);
   }
}


 
int main()
{   int n,sum;
   cin>>n>>sum;
   int a[n+1]; 
   a[0]=0;
   for(int i=1;i<=n;i++) cin>>a[i];
 
 int ans[n+1];
   ans[0]=0;
   ss(a,ans,1,n,sum);
   return 0;
}

/*
4    
4 2 3 1
4 2 3 1 
4 2 1 3
4 3 2 1
4 3 1 2
4 1 2 3
4 1 3 2
2 4 3 1
2 4 1 3
2 3 4 1
2 3 1 4
2 1 4 3
2 1 3 4
3 4 2 1
3 4 1 2
3 2 4 1
3 2 1 4
3 1 4 2
3 1 2 4
1 4 2 3
1 4 3 2
1 2 4 3
1 2 3 4
1 3 4 2
1 3 2 4


*/

/*repeating 


3
2 1 3
2 2 2 
2 2 1
2 2 3
2 1 2
2 1 1
2 1 3
2 3 2
2 3 1
2 3 3
1 2 2
1 2 1
1 2 3
1 1 2
1 1 1
1 1 3 
1 3 2
1 3 1
1 3 3
3 2 2
3 2 1
3 2 3
3 1 2
3 1 1
3 1 3
3 3 2
3 3 1
3 3 3


*/