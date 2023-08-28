#include<bits/stdc++.h>
using namespace std;


//closet pair -brute force
class point{
public:
    int x,y;
};


//O(n^2)

int main(){
int n;cin>>n;
point p[n];
for(int i=0;i<n;i++){
    cin>>p[i].x>>p[i].y;
}
point a,b; 
double mini=INT_MAX;
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        int d=(p[j].x-p[i].x)*(p[j].x-p[i].x)+(p[j].y-p[i].y)*(p[j].y-p[i].y);
        double val=sqrt(d);
        if(mini>val){
            a=p[i];
            b=p[j];
            mini=val;
        }
    }
}

cout<<"closest pairs are "<<a.x<<","<<a.y<<" and "<<b.x<<","<<b.y<<endl;
cout<<mini<<endl; 

    
}

/*
6
2 3
5 1
12 30
40 50
12 10
3 4


closest pairs are 2,3 and 3,4
1.41421


*/