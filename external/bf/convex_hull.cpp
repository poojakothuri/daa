#include<bits/stdc++.h>
using namespace std;


//convex hull
//a smallest polygon which encloses all the points
/*
a=y2-y1
b=x1-x2
c=y1x2-y2x1 

ax+bx+c=0;

if all points are towards one side of a line segment then  the 
linesegment is one of the edges
*/
 
 //O(n^3)

class point{
public:
    int x,y;
};



int main(){
int n;cin>>n;
point p[n];
for(int i=0;i<n;i++){
    cin>>p[i].x>>p[i].y;
}
int a,b,c;
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        a=p[j].y-p[i].y;
        b=p[i].x-p[j].x;
        c=p[i].y*p[j].x-p[j].y*p[i].x; 

        int ps=0,ns=0;
        
     //checking whether n-2 points lie on the same line of point p[i],p[j];

        for(int k=0;k<n;k++){
            int val=a*p[k].x+b*p[k].y+c; //ax+by+c
            if(val>0) ps++;
            if(val<0) ns++;
        } 
        if(ps==0 || ns==0) //if either of them are 0 that implies that all points are towards one side
            cout<<p[i].x<<","<<p[i].y<<" "<<p[j].x<<","<<p[j].y<<endl;
    }
}

    
}

/*
6
0 0
0 4
-4 0
5 0
0 -6
1 0 


0,4 -4,0
0,4 5,0
-4,0 0,-6
5,0 0,-6

*/