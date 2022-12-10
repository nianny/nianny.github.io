#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,q;
    cin>>n>>q;

    string a = string(n, '1');
    // cout<<a;

    for (int i=0; i<q; i++){
        int l,r;
        char d;
        cin>>l>>r>>d;

        for (int p=l-1; p<r; p++){
            a[p] = d;
        }

        int ans = 0;
        for (int p=0; p<n; p++){
            ans = (ans*10 + (a[p]-'0')) % 998244353;
        }

        cout<<ans<<'\n';
    }
    
    return 0;
}
