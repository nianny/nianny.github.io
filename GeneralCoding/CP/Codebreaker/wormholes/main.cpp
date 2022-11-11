#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,w;
    cin>>n>>w;

    vector<int> adjList[n+5];
    for (int i=0; i<w; i++){
        int a,b;
        cin>>a>>b;

        adjList[b].push_back(a);
    }

    int dp[n+5];
    dp[0] = 0;
    for (int i=1; i<n; i++){
        dp[i] = dp[i-1];
        
        for (auto p: adjList[i]){
            dp[i] = min(dp[i], dp[p]);
        }
        dp[i]++;
    }
    cout<<dp[n-1];
    
    return 0;
}
