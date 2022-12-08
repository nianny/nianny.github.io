#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;

    int dist[1000];
    memset(dist, -1, sizeof dist);
    deque<pair<int,int>> q;
    q.push_back({0, 1});
    dist[1] = 0;

    while (!q.empty()){
        auto [d, node] = q.front();

        if (dist[node] != d) continue;

        for (auto [n,w]: adj[node]){
            if (dist[n] == -1 || dist[n] > d + w){
                dist[n] = d+w;
                if (w == 0){
                    q.push_front({dist[n], n});
                }
                else{
                    q.push_back({dist[n], n});
                }
            }
        }
    }
    
    
    return 0;
}
