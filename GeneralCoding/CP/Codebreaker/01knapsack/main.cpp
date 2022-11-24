#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n,w;
int W[110];
int V[110];

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    
    cin>>n>>w;
    int dp[110][w+10];
    for (int i=1; i<=n; i++){
        cin>>W[i];
        cin>>V[i];
    }


    for (int i=0; i<=n; i++){
        for (int p=0; p<=w; p++){
            if (i==0 || p ==0) dp[i][p] = 0;
            else if (p < W[i]) dp[i][p] = dp[i-1][p];
            else{
                dp[i][p] = max(dp[i-1][p], dp[i-1][p-W[i]] + V[i]);
            }
        }
    }
    
    // for (int i=0; i<=n; i++){
    //     for (int p=0; p<=w; p++){
    //         cout<<dp[i][p]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<dp[n][w];
    return 0;
}
