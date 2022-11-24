#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    // cout<<n;
    vector<pair<int,int>> adjList[n+1];
    for (int i=0; i<n-1; i++){
        int a,b,h;
        cin>>a>>b>>h;

        adjList[a].push_back({b,h});
        adjList[b].push_back({a,-h});
    }

    int dist[n+1];
    memset(dist, -1, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()){
        int c = q.front();
        q.pop();

        for (auto i: adjList[c]){
            if (dist[i.first] != -1) continue;
            dist[i.first] = dist[c] + i.second;
            q.push(i.first);
        }
    }

    int Q;
    cin>>Q;
    // cout<<Q;
    for (int i=0; i<Q; i++){
        int x,y;
        cin>>x>>y;
        
        cout<<dist[y] - dist[x]<<'\n';
    }
    return 0;
}