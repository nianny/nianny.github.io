#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,m,s;
    cin>>n>>m>>s;

    int M[m];
    int S[s];

    for (int i=0; i<m; i++){
        cin>>M[i];
    }
    for (int i=0; i<s; i++){
        cin>>S[i];
    }

    sort(M, M+m);
    sort(S, S+s);
    int ans = 0;
    for (int i=0; i<n; i++){
        ans = max(ans, M[i]+S[n-1-i]);
    }
    cout<<ans;
    /*
    Hallooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    */
    return 0;
}

