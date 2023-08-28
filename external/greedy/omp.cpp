#include<bits/stdc++.h>
using namespace std;

//optimal merge pattern
//min heap

void minheap(vector<int> &a,int i){
    int l=2*i+1;
    int r=2*i+2;
    int smallest=i;
    if(l<a.size() && a[l]<a[smallest]){
        smallest=l;
    }
    if(r<a.size() && a[r]<a[smallest]){
        smallest=r;
    }
    if(smallest!=i){
        swap(a[smallest],a[i]);
        minheap(a,smallest);
    }
 
    
} 





int f(vector<int> &v,int n){  
    int s=0;
    while(v.size()>1){ 
        minheap(v,0);
     int a=v[0];
     v.erase(v.begin());
     minheap(v,0);
     int b=v[0];
     v.erase(v.begin());  
     v.push_back(a+b);
     s+=a+b;
    }

return s;
}


int omp(int n,int a[]){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++) pq.push(a[i]); 
        int s=0;

    while(pq.size()>1){
        int a=pq.top();pq.pop();
        int b=pq.top();pq.pop();
        pq.push(a+b);
        s+=a+b; 
    } 
    return s;
}

int main(){ 
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
  
    cout<<omp(n,a)<<endl; 
 vector<int> v(n);
   for(int i=0;i<n;i++) v[i]=a[i];
//    for(int i=n/2-1;i>=0;i--){
//     minheap(v,i);
//    }
  
 cout<<f(v,n)<<endl;
 }
 

 /*
 5
20 35 40 50 60

465
 
 */
    
