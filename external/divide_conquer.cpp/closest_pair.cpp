#include<bits/stdc++.h>
using namespace std;


//closest pair 
class point{
public:
    int x,y;
};

void sortpoints(point p[],int n){

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
           if(p[j].x>p[j+1].x){
            point t=p[j];
            p[j]=p[j+1];
            p[j+1]=t;
           }
        }
    }
}
double bruteforce(point p[],int start,int end){
     double mini=INT_MAX;
   for(int i=start;i<end;i++){
    for(int j=i+1;j<=end;j++){
        double d=(p[j].x-p[i].x)*(p[j].x-p[i].x)+(p[j].y-p[i].y)*(p[j].y-p[i].y);
        double val=sqrt(d);
        if(mini>val){
            mini=val;
        }
    }
} 
return mini;


}
double closest_pair(point p[],int start,int end){

    if(end-start<3){
        return bruteforce(p,start,end);
    }
   int mid=(start+end)/2;
   double dl=closest_pair(p,start,mid);
   double dr=closest_pair(p,mid+1,end); 
   double mini=min(dl,dr);

   point strip[100];
   int k=0;
   for(int i=start;i<=end;i++){
    if(p[i].x>=p[mid].x-mini && p[i].x<=p[mid].x+mini) 
        strip[k++]=p[i];
   }
   double least=bruteforce(strip,0,k-1); 

   return min(least,mini);





}


int main(){
int n;cin>>n; 
point p[n];

for(int i=0;i<n;i++){
    cin>>p[i].x>>p[i].y;
}
sortpoints(p,n); 
cout<<closest_pair(p,0,n-1)<<endl;

    
}

/*
6
2 3
5 1
12 30
40 50
12 10
3 4
1.41421

*/