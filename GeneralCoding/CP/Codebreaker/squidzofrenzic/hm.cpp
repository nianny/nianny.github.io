#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main(){
    int x;
    cin>>x;
    int a;
    for(int i=0;i<x;i++){
        cin>>a;
        long long l =0,h=(1e6);
        while (h-l>1){
            long long middle=(h+1)/2;
            long long testCbrt = middle*middle*middle;
            if (testCbrt <=a){
                l=middle;
            } else {
                h=middle;
            }
        } 
        cout<<l<<"\n";
}
    
}