#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int a,b,c,x;
    int ans = 0;
    cin>>a>>b>>c>>x;
    for (int i=0; i<=a; i++){
        for (int p=0; p<=b; p++){
            for (int m = 0; m<=c; m++){
                if ((i*500 + p*100 + m*50 )== x){
                    ans ++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}