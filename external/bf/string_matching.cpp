#include<bits/stdc++.h>
using namespace std;


//string matching  

//O(l*m)

int main(){

    string s1,s2;
    cin>>s1>>s2;
    int l=s1.length();
    int m=s2.length();
 
    if(m>l) cout<<"string not found\n";
    else{ 
        int f=1;
        for(int i=0;i<l-m+1;i++){ //
            for(int j=i;j<i+m;j++){
                  f=1;
                  if(s1[j]!=s2[j-i]){
                       f=0;
                       break;
                  }
            } 
            if(f==1){
                cout<<"string found at index "<<i<<endl;
                break;
            }
        } 
        if(f==0) cout<<"string not found\n";
    }
    
}
 
 /*abbcaabbcabc
 
 aab*/