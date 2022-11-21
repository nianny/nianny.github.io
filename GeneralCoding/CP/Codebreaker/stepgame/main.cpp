#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;

    int mas[n+5];
    mas[0] = 0;

    for (int i=1; i<=n; i++){
        int a;
        cin>>a;
        mas[i] = min(mas[i-1]+a, a);
    }
    int ans = LLONG_MAX;
    for (int i=1; i<=n; i++){
        ans = min(ans, mas[i]);
    }
    cout<<ans;
    return 0;
}
