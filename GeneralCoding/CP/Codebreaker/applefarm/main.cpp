#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,m,a,b,c;
    cin>>n>>m>>a>>b>>c;

    vector<pair<int,int>> adjlist[n+5];
    vector<pair<int,int>> adjlist_sum[n+5];

    for (int i=0; i<m; i++){
        int u,v,f,s;
        cin>>u>>v>>f>>s;

        adjlist[u].push_back({v, f});
        adjlist_sum[u].push_back({v, f+s});
        adjlist[v].push_back({u, f});
        adjlist_sum[v].push_back({u, f+s});
    }

    // for (int i=1; i<=n; i++){
    //     cout<<i<<'\t';
    //     for (auto p: adjlist[i]){
    //         cout<<p.first<<' '<<p.second<<'\t';
    //     }
    //     cout<<'\n';
    // }


    //dijkstra from a and c
    int dista[n+5];
    memset(dista, -1, sizeof dista);
    dista[a] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, a});

    while (!pq.empty()){
        auto top = pq.top();
        pq.pop();

        if (dista[top.second] != top.first) continue;
        for (auto i: adjlist[top.second]){
            if (dista[i.first] == -1 || dista[i.first] > top.first + i.second){
                dista[i.first] = top.first + i.second;
                pq.push({dista[i.first], i.first});
            }
        }
    }

    int distc[n+5];
    memset(distc, -1, sizeof distc);
    distc[c] = 0;
    pq.push({0, c});

    while (!pq.empty()){
        auto top = pq.top(); pq.pop();
        if (top.first != distc[top.second]) continue;

        for (auto i: adjlist[top.second]){
            if (distc[i.first] == -1 || distc[i.first] > top.first + i.second){
                distc[i.first] = top.first + i.second;
                pq.push({distc[i.first], i.first});
            }
        }
    }

    int distb[n+5];
    memset(distb, -1, sizeof distb);
    distb[b] = 0;
    pq.push({0, b});

    while (!pq.empty()){
        auto top = pq.top(); pq.pop();
        if (top.first != distb[top.second]) continue;

        for (auto i: adjlist_sum[top.second]){
            if (distb[i.first] == -1 || distb[i.first] > top.first + i.second){
                distb[i.first] = top.first + i.second;
                pq.push({distb[i.first], i.first});
            }
        }
    }

    // for (int i=1; i<=n; i++){
    //     cout<<dista[i]<<' ';
    // }
    // cout<<'\n';
    // for (int i=1; i<=n; i++){
    //     cout<<distb[i]<<' ';
    // }
    // cout<<'\n';
    // for (int i=1; i<=n; i++){
    //     cout<<distc[i]<<' ';
    // }
    // cout<<'\n';
    int ans = LLONG_MAX;
    for (int i=1; i<=n; i++){
        // if (dista[i] == -1 || distc[i] == -1|| distb[i] == -1) continue;
        ans = min(ans, dista[i] + distc[i] + distb[i]);
    }
    if (ans == LLONG_MAX) return ans;
    cout<<ans;
    
    return 0;
}
