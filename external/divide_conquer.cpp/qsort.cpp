#include<bits/stdc++.h>
using namespace std;


//quick sort
//O(nlogn)

int partition(int a[],int low,int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    i++;
    swap(a[high],a[i]);
    return i;
}


void qs(int a[],int low,int high){
    if(low<high){
        int pivot=partition(a,low,high);
        qs(a,low,pivot-1);
        qs(a,pivot+1,high);
    }
}


int main(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
   qs(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}

/*
10
102 458 90 12345 98765
123 1 68 1234 556789


1 68 90 102 123 458 1234 12345 98765 556789 
*/