#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    double ans = 0;
    for (int i=1; i<50; i++){
        int num = 1;
        for (int p=1; p<=i; p++){
            num *= p;
        }
        ans += (double)1/num;
        cout<<ans<<'\n';
    }    
    cout << ans;
    return 0;
}
