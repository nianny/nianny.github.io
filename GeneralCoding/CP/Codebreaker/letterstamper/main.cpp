#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
string s;
int memo[310][310][26];
int dp(int start, int end, int top_letter){
    if (memo[start][end][top_letter] != -1) return memo[start][end][top_letter];

    if (start > end) return memo[start][end][top_letter] = 0;
    if (top_letter == s[start]-'A'){
        return memo[start][end][top_letter] = dp(start+1, end, top_letter);
    }
    else{
        int ans = LLONG_MAX;
        
        for (int i=start; i<=end; i++){
            ans = min(ans, dp(start+1, i, s[start]-'A') + dp(i+1, end, top_letter));
        }
        ans++;
        return memo[start][end][top_letter] = ans;
    }
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    memset(memo, -1, sizeof memo);
    cin>>s;
    
    
    cout<<(dp(0,s.size()-1, s[0]-'A')+1)*2+s.size()<<'\n';
    // cout<<s[0]-'A'<<'\n';
    
    return 0;
}
