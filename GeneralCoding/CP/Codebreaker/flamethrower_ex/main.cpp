#include <bits/stdc++.h>
using namespace std;
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// // #pragma GCC optimize("Ofast")//Comment optimisations for interactive problems (use endl)
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

int32_t main() {
    hallo;
    int n,k;
    cin>>n>>k;

    int arr[n+5];
    int ss[n+5];

    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }

    ss[0] = 0;
    for (int i=1; i<=n; i++){
        ss[i] = ss[i-1] + arr[i];
    }

    deque<pair<int,int>>dq; // min_value, index
    // int l=0;
    int ans = 0;
    for (int r=0; r<=n; r++){
        if (dq.empty()){
            dq.push_back({ss[r], r});
            continue;
        }
        ans = max(ans, ss[r] - dq.front().first);

        while (!dq.empty() && dq.back().first >= ss[r]){
            dq.pop_back();
        }
        dq.push_back({ss[r], r});

        while (!dq.empty() && dq.front().second < r-k+1){
            dq.pop_front();
        }
    }

    



    cout << ans;

    return 0;
}
