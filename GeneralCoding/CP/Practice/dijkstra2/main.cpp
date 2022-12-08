#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,e;
    cin>>n>>e;

    vector<pair<int,int>> adjl[n+5];
    for (int i=0; i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjl[a].push_back({b,c});
        adjl[b].push_back({a,c});
    }

    int dist[n+5];
    memset(dist, -1, sizeof dist);

    dist[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    pq.push({0, 1});

    while (!pq.empty()){
        auto c = pq.top(); pq.pop();
        if (dist[c.second] != c.first) continue;

        for (auto i: adjl[c.second]){
            if (dist[i.first] == -1 || dist[i.first] > c.first + i.second){
                dist[i.first] = c.first + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }

    cout<<dist[n];
    
    return 0;
}
