#include <bits/stdc++.h>
using namespace std;
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("Ofast")//Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

int32_t main() {
    hallo;
    int N, K;
    cin >> N >> K;
    int trees[N];
    int cost = 0;
    int maxCost = 0;

    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i; j < min(N, i+K); j++){
            cost += trees[j];
            maxCost = max(maxCost, cost);
        }
        
        cost = 0;
    }

    cout << maxCost;

    return 0;
}
