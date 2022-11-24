#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n,w;
    cin>>n>>w;
    int W[n+5];
    int V[n+5];

    for (int i=1; i<=n; i++){
        cin>>W[i]>>V[i];
    }

    int dp[n+5][w+5];
    for (int i=0; i<=n; i++){
        for (int p=0; p<=w; p++){
            if (i==0 || p==0) dp[i][p] = 0;
            else if (p < W[i]) dp[i][p] = dp[i-1][p];
            else{
                dp[i][p] = max(dp[i-1][p], dp[i-1][p-W[i]] + V[i]);
            }
        }
    }

    cout<<dp[n][w];
}