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
    vector<pair<int,int>> adjlist[n+5];

    for (int i=0; i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int dist[n+5];
    memset(dist, -1, sizeof dist);
    // fill(dist, dist+n+5, 10e9);
    dist[1] = 0;
    pq.push({0,1}); //dist, node


    while (!pq.empty()){
        auto c = pq.top(); pq.pop();
        if (dist[c.second] != c.first) continue;

        for (auto [node, w]: adjlist[c.second]){
            if (dist[node] == -1 || dist[node] > c.first + w){
                dist[node] = c.first + w;
                pq.push({dist[node], node});
            }
        }
    }
    // if (dist[n] == 1e9) cout<< -1;
    // else{
    //     cout<<dist[n];
    // }
    cout<<dist[n];


    

    


    
    
    return 0;
}
