#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int memo[105][105];
int dp(int x, int y){ // y = index considering adding
    if (memo[x][y] != -1) return memo[x][y];

    if (x == 5) return memo[x][y] = 1;
    
    memo[x][y] = 1;
    for (int i = y; 2*i <= x; i++){
        memo[x][y] += dp(x-i, i);
    }

    return memo[x][y];
} 
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;

    memset(memo, -1, sizeof(memo));
    cout<<dp(n, 5)<<endl;

    /*
    Hallooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    */
    return 0;
}

