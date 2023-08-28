#include <bits/stdc++.h> 
using namespace std;

bool issafe(int a[],int ans[],int ind,int node,int n){
    for(int i=1;i<ind;i++){
       if(ans[i]==a[node]) return false;
    }
    return true;
}

void p(int a[],int ans[],int ind,int n){
    if(ind==n+1){
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl; 
        return;
    } 
    for(int i=1;i<=n;i++){
      // if(issafe(a,ans,ind,i,n)==true){ //if issafe function is removed then the permutations repeats
            ans[ind]=a[i];
            p(a,ans,ind+1,n);
       //}
    }
}



int main()
{   int n;
   cin>>n;
   int a[n+1]; 
   a[0]=0;
   for(int i=1;i<=n;i++) cin>>a[i];
 
int ans[n+1];
  ans[0]=0;
   p(a,ans,1,n);
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