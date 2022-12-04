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

    for (int i=1; i<=n; i++){
        cout<<i<<'\t';
        for (auto p: adjlist[i]){
            cout<<adjlist[i].first<<' '<<adjlist[i].second<<'\t';
        }
    }


    //dijkstra from a and c
    int dista[n+5];
    memset(dista, -1, sizeof dista);
    dista[a] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, a});

    while (!pq.empty()){
        auto c = pq.top();
        pq.pop();

        if (dista[c.second] != c.first) continue;
        for (auto i: adjlist[c.second]){
            if (dista[i.first] == -1 || dista[i.first] > c.first + dista[c.second]){
                dista[i.first] = c.first + dista[c.second];
                pq.push({dista[i.first], i.first});
            }
        }
    }

    int distc[n+5];
    memset(distc, -1, sizeof distc);
    distc[c] = 0;
    pq.push({0, c});

    while (!pq.empty()){
        auto c = pq.top(); pq.pop();
        if (c.first != distc[c.second]) continue;

        for (auto i: adjlist[c.second]){
            if (distc[i.first] == -1 || distc[i.first] > c.first + distc[c.second]){
                distc[i.first] = c.first + distc[c.second];
                pq.push({distc[i.first], i.first});
            }
        }
    }

    int distb[n+5];
    memset(distb, -1, sizeof distb);
    distb[b] = 0;
    pq.push({0, b});

    while (!pq.empty()){
        auto c = pq.top(); pq.pop();
        if (c.first != distb[c.second]) continue;

        for (auto i: adjlist_sum[c.second]){
            if (distb[i.first] == -1 || distb[i.first] > c.first + distc[c.second]){
                distb[i.first] = c.first + distb[c.second];
                pq.push({distb[i.first], i.first});
            }
        }
    }

    for (int i=1; i<=n; i++){
        cout<<dista[i]<<' ';
    }
    cout<<'\n';
    for (int i=1; i<=n; i++){
        cout<<distb[i]<<' ';
    }
    cout<<'\n';
    for (int i=1; i<=n; i++){
        cout<<distc[i]<<' ';
    }
    cout<<'\n';
    int ans = INT_MAX;
    for (int i=1; i<=n; i++){
        if (dista[i] == -1 || distc[i] == -1|| distb[i] == -1) continue;
        ans = min(ans, dista[i] + distc[i] + distb[i]);
    }
    cout<<ans;
    
    return 0;
}
