#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
string a;
unsigned long long dp[1000];
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
    
    for (int i=0; i<a.length(); i++){
        if (a[i] < 'a' || a[i] > 'z') continue;
        if (a[i] == 'a')dp[(int)a[i]]++;
        else dp[(int)a[i]] += dp[(int)a[i]-1];
    }

    cout<<dp[(int)'z'];
    return 0;
}
