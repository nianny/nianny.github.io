#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,h;
    cin>>n>>h;

    int ans = 0;
    for (int i=0; i<n; i++){
        int height;
        cin>>height;
        if (height > h){
            ans += 2;
        }
        else ans++;
    }

    cout<<ans;
    return 0;
}

