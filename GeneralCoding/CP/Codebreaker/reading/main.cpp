#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,k;
    cin>>n>>k;
    int ans = 0;
    for (int i=0; i<n; i++){
        int w,p;
        cin>>w>>p;
        if ((__int128)w * (__int128)p < (__int128)k) ans++;
    }
    cout<<ans;
    
    return 0;
}
