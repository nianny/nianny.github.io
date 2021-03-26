#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int t;
    cin>>t;
    
    for (int i=0; i<t; i++){
        int n,m,num;
        cin>>n>>m>>num;

        int x,y;
        x = num/m;
        y = num % m;
        
        if (y ==0){
            y = m;
        }
        y--;

        int ans = y*n + x;

        cout<<x<<' '<<y<<' '<<ans;

        
    }
    return 0;
}