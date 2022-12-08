#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,e;
    cin>>n>>e;
    int limit = 10000;

    vector<pair<int,int>> adjl[n+5];
    for (int i=0; i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjl[a].push_back({b,c});
        adjl[b].push_back({a,c});
    }

    int dist[n+5];
    memset(dist, -1, sizeof dist);

    vector<int>buckets[limit];
    buckets[0].push_back(1);
    dist[1] = 0;

    int curr = 0;
    while(curr < limit){
        if (buckets[curr].empty()){
            curr++;
            continue;
        }

        auto c = buckets[curr].back();
        buckets[curr].pop_back();

        if (dist[c] != curr) continue;

        for (auto [node, w]: adjl[c]){
            if (dist[node] == -1 || dist[node] > curr + w){
                dist[node] = curr + w;
                buckets[dist[node]].push_back(node);
            }
        }
    }

    cout<<dist[n];
    
    return 0;
}
