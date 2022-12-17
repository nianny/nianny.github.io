#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int memo[5010][5010];
int n,m,t;
vector<pair<int,int>>adjlist[5010];

struct node{
    int s,e,m;
    int val;
    node *l =nullptr, *r=nullptr;


};
int dp(int node, int time){
    if (memo[node][time] != -1) return memo[node][time];
    if (time < 0) return 0;
    if (node <= 0) return 1;
    

    int ans = 0;

    for (auto [a,b]: adjlist[node]){
        ans = max(ans, dp(a, time));
        ans = max(ans, dp(a, time-b)+1);
    }

    return memo[node][time] = ans;


}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    memset(memo, -1, sizeof memo);
    cin>>n>>m>>t;

    for (int i=0; i<m; i++){
        int u,v,d;
        cin>>u>>v>>d;
        adjlist[v].push_back({u,d});
    }

    cout<<dp(n,t);
    
    
    return 0;
}
