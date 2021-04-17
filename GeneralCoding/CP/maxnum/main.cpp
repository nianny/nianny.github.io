#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int ans = 0;
    for (int a = 1; a<64; a++){
        for (int b = 1; b<64-a; b++){
            for (int c = 1; c<64-a-b; c++){
                for (int d = 1; d<64-a-b-c; d++){
                    ans = max(ans, a*b + b*c + c*d);
                }
            }
        }
    }
    cout<<ans;
    return 0;
}