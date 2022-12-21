#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
vector<pair<int,int>> adjl[500010];
int dist[500010];
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int v,e,q;
    cin>>v>>e>>q;
    for (int i=0; i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjl[a].push_back({b,c});
        adjl[b].push_back({a,c});
    }


    priority_queue<pair<int,int>> pq;
    memset(dist, -1, sizeof dist);
    dist[1] = LLONG_MAX;
    pq.push({LLONG_MAX, 1});

    while (!pq.empty()){
        auto c = pq.top(); pq.pop();

        if (dist[c.second] != c.first) continue;

        for (auto [node, attract]: adjl[c.second]){
            if (dist[node] == -1 || dist[node] < min(attract, c.first)){
                dist[node] = min(attract, c.first);
                pq.push({dist[node], node});
            }
        }
    }

    for (int i=0; i<q; i++){
        int x;
        cin>>x;

        cout<<dist[x]<<'\n';
    }
    return 0;
}
