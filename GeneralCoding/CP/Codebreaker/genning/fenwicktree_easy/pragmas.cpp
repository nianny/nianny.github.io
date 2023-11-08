#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("Ofast")//Comment optimisations for interactive problems (use endl)
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
int arr[1000010];
int ss[1000010];
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }

    int m;
    cin>>m;
    for (int i=0; i<m; i++){
        int t;
        cin>>t;

        if (t==1){
            int a,b;
            cin>>a>>b;
            arr[a] = b;
        }
        else {
            int a,b;
            cin>>a>>b;
            int ans = 0;
            for (int i=a; i<=b; i++){
                ans += arr[i];
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
