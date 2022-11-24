#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
string a;
unsigned long long dp[1000010][30];
bool visited[1000010][30];
unsigned long long func(int s, int pos){
    if (visited[s][pos]) return dp[s][pos];
    visited[s][pos] = true;
    if (pos > 25) return dp[s][pos] = 1;
    if (s == a.length()) return dp[s][pos] = 0;

    dp[s][pos] = func(s+1,pos);
    if (pos == a[s]-'a') dp[s][pos] += func(s+1,pos+1);

    return dp[s][pos];
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    // memset(dp, -1, sizeof(dp));
    hallo;
    // string b;
    // while (cin>>b){
    //     a+=b;
    // }

    getline(cin, a);
    // cin>>a;
    // tolower(a);
    for(int i=0; i<a.length(); i++) a[i] = tolower(a[i]);
    cout<<func(0, 0);
    return 0;
}
