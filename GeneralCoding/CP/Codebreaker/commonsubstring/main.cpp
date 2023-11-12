#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
string a,b;
int memo[5000][5000];
int dp(int A, int B){
    if (memo[A][B] != -1) return memo[A][B];
    if (A == a.size() || B == b.size()) return memo[A][B] = 0;

    if (a[A] == b[B]) return memo[A][B] = 1 + dp(A+1,B+1);
    else {
        return memo[A][B] = 0;
    }
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    memset(memo,-1,sizeof(memo));
    cin>>a>>b;

    // cout<<dp(0,0)<<'\n';
    int ans = 0;
    for (int i=0; i<a.size(); i++){
        for (int y=0; y<b.size(); y++){
            ans = max(ans, dp(i,y));
            // cout<<dp(i,y)<<' ';
        }
        // cout<<'\n';
    }
    cout<<max(0LL, ans)<<'\n';
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

