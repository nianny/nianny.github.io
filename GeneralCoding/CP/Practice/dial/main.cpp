#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int lim = 10000;
    int dist[10010];
    vector<pair<int,int>> adjlist[10010];
    vector<int> bucket[lim+100];
    
    int v,e;
    cin>>v>>e;
    
    for (int i=0; i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }

    for (int i=1; i<=v; i++){
        dist[i] = 1e9;
    }
    dist[1] = 0;
    bucket[0].push_back(1);

    int curr = 0;
    while (curr <= lim){
        if (bucket[curr].empty()){
            curr++;
            continue;
        }

        int u = bucket[curr].back();
        bucket[curr].pop_back();

        if (curr != dist[u]) continue; // not updated
        for (auto [V,W]: adjlist[u]){
            if (curr + W < dist[V]){
                dist[V] = curr + W;
                bucket[dist[V]].push_back(V);
            }
        }
    }

    cout<<dist[v];
    return 0;
}
