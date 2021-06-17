#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int weights[505];
int value[505];
int memo[505][505];
int dp(int i, int w){
    if (i==0) return 0;
    if (memo[i][w] != -1) return memo[i][w];

    memo[i][w] = dp(i-1, w);
    if (w >= weights[i]) memo[i][w] = max(memo[i][w], dp(i-1, w-weights[i])+value[i]);
    if (w > 0) memo[i][w] = max(memo[i][w], dp(i, w-1));
    return memo[i][w];
}

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    memset(memo, -1, sizeof memo);
    cin>>n>>m;
    for (int i=1; i<=n; i++){
        cin>>weights[i];
        cin>>value[i];
    }
    cout<<dp(n,m);
    return 0;
}
