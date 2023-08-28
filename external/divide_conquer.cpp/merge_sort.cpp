#include<bits/stdc++.h>
using namespace std;


//merge sort

void merge(int a[],int low,int mid,int high){
  int l=mid-low+1;
  int r=high-mid;
  int la[l],ra[r];
  for(int i=0;i<l;i++) la[i]=a[low+i];
  for(int i=0;i<r;i++) ra[i]=a[mid+1+i];

  int k=low,i=0,j=0;
  while(i<l && j<r){
    if(la[i]<=ra[j]){
        a[k]=la[i];
        i++;
        k++;
    }
    else{
        a[k]=ra[j];
        j++;
        k++;
    }
  } 

  while(i<l){
    a[k]=la[i];
    k++;i++;
  }

  while(j<r){
     a[k]=ra[j];
     j++; k++;
  }
}


void mergesort(int a[],int low,int high){
    if(low<high){
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high); 
        merge(a,low,mid,high);
    }
}


int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
   mergesort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}

/*
10
102 458 90 12345 98765
123 1 68 1234 556789


1 68 90 102 123 458 1234 12345 98765 556789 
*/