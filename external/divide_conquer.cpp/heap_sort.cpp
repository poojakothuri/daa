#include<bits/stdc++.h>
using namespace std;


//heap sort  



void miniheapify(int a[],int size,int ind){
    int smallest=ind;
    int lc=2*ind+1;
    int rc=2*ind+2;
    if(lc<size && a[lc]< a[smallest]) smallest=lc;
    if(rc<size && a[rc] < a[smallest]) smallest=rc;

    if(ind!=smallest){
        swap(a[ind],a[smallest]);
        miniheapify(a,size,smallest);
    }
}

void minheap(int a[],int start,int n){
    for(int i=(n/2)-1;i>=0;i--){
        miniheapify(a,n,i);
    }

    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        miniheapify(a,i,0) ;
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
            cout<<endl;
    } 
}


void heapify(int a[],int size,int ind){
    int largest=ind;
    int lc=2*ind+1;
    int rc=2*ind+2;
    if(lc<size && a[lc]> a[largest]) largest=lc;
    if(rc<size && a[rc] > a[largest]) largest=rc;

    if(ind!=largest){
        swap(a[ind],a[largest]);
        heapify(a,size,largest);
    }
}

void maxheap(int a[],int start,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,n,i);
    }

    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
  // maxheap(a,0,n);
  //   for(int i=0;i<n;i++) cout<<a[i]<<" ";  
  //       cout<<endl;

      minheap(a,0,n);
    for(int i=n-1;i>=0;i--) cout<<a[i]<<" ";
}

/*
10
102 458 90 12345 98765
123 1 68 1234 556789


1 68 90 102 123 458 1234 12345 98765 556789 
*/