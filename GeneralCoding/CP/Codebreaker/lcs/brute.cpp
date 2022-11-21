#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int dp[1010][1010];
string a,b;
int lcs(int la, int lb){
    if (la < 0 || lb < 0) return 0;
    if (dp[la][lb] != -1) return dp[la][lb];
    
    int ans = 0;
    

    ans = max(ans, max(lcs(la-1, lb), lcs(la, lb-1)));
    if (a[la] == b[lb]){
        ans = lcs(la-1, lb-1)+1;
        // cout<<a<<' '<<b<<' '<<a[la]<<' '<<b[lb]<<' '<<la<<' '<<lb<<' '<<ans<<'\n';
    }
    


    dp[la][lb] = ans;
    return dp[la][lb];

}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    cin>>a>>b;
    // cout<<a<<' '<<b<<'\n';
    memset(dp, -1, sizeof dp);
    cout<<lcs(a.length()-1, b.length()-1);
    // cout<<a<<' '<<b<<'\n';


    
    return 0;
}
