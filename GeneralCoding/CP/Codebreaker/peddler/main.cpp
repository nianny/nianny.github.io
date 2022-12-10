#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n,m;
// bool visited[100010];
int memo[200010];
int arr[200010];
vector<int>adjlist[200010];

// pair<int,int> dfs(int x){ //low, high
//     if (visited[x]) return {INT_MAX,0};
//     if (adjlist[x].size() == 0) return {arr[x], arr[x]};



//     for (auto i: adjlist[x]){
//         auto [a,b] = dfs(i);
//         a = min(a, arr[x]);
//         b = max(b, arr[x]);
//     }
// }

int dp(int x){
    if (memo[x] != -1) return memo[x];
    int ans = LLONG_MAX;
    for (auto i: adjlist[x]){
        ans = min(ans, dp(i));
        ans = min(ans, arr[i]);
    }
    // ans = min(arr[x], ans);
    return memo[x] = ans;
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    memset(memo, -1, sizeof memo);
    // int n,m;
    cin>>n>>m;

    
    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }
    

    for (int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        adjlist[y].push_back(x);
    }

    int ans = LLONG_MIN;
    for (int i=1; i<=n; i++){
        // cout<<i<<' '<<dp(i)<<'\n';
        if (arr[i] - dp(i) == 0) continue;
        ans = max(ans, arr[i] - dp(i));
    }

    
    //memset(visited, false, sizeof visited);

    // visited[1] = true;
    // queue<int>q;
    // q.push(1);

    // while(!q.empty()){
    //     auto c = q.front(); q.pop();

    //     for (auto i: adjlist[c]){
    //         if (visited[i]) continue;
    //         else{
    //             visited[i] = true;
    //             q.push(i);
    //         }
    //     }
    // }

    // vector<int>possibilities;

    // for (int i=1; i<=n; i++){
    //     if (visited[i]){
    //         possibilities.push_back(i);
    //     }
    // }

    // int ans = 0;
    // for (int i=0; i<possibilities.size(); i++){
    //     for (int p=i+1; p<possibilities.size(); p++){
    //         ans = max(ans, arr[p]-arr[i]);
    //     }
    // }

    cout<<ans<<'\n';
    return 0;
}
