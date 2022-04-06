#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n,m,k;
int memo[2005][2005];
int dp(int pos, int diff){
    if (memo[pos][diff] != -1) return memo[pos][diff];

    if (pos <= diff){memo[pos][diff] = 0;}
    else if (pos == 0) memo[pos][diff] = 1;
    else if (diff == 0) memo[pos][diff] = m;
    else {
        memo[pos][diff] = dp(pos-1, diff) + dp(pos-1, diff-1)*(m-1);
    }
    memo[pos][diff] %= 998244353;
    return memo[pos][diff];
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    cin>>n>>m>>k;
    memset(memo, -1, sizeof memo);

    
    cout<<dp(n,k)<<'\n';
    // for (int i=0; i<=n; i++){
    //     for (int p=0; p<=n; p++){
    //         // cout<<i<<' '<<p<<'\n';
    //         cout<<memo[i][p]<<" ";
    //     }
    //     cout<<'\n';
    // }
    // cout<<memo[n][k];

    
    
    return 0;
}
