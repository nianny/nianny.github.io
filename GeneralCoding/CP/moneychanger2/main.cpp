#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define INF 2147483647

int dp[10010];
int coins[105];
int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n,v;
    cin>>n>>v;
    for (int i=0; i<n; i++){
        cin>>coins[i];
    }
    
    dp[0] = 0;
    for (int i=1; i<=v; i++){
        dp[i] = INF;
        for (int p=0; p<n; p++){
            if (i >= coins[p]){
                dp[i] = min(dp[i], dp[i-coins[p]]+1);
            }
        }
    }
    if (dp[v] == INF){
        cout<<-1;
    }
    else cout<<dp[v];
    return 0;
}
