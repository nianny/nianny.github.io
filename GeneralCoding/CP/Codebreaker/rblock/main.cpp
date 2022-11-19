#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,m;
    cin>>n>>m;
    int adjm[n+5][n+5];
    
    for (int i=1; i<= n; i++){
        for (int j=1; j<=1; j++){
            adjm[i][j] = INT_MAX;
            cout<<adjm[i][j]<<' ';
        }
        cout<<'\n';
    }

    for (int i=0; i<m; i++){
        int a,b,l;
        cin>>a>>b>>l;

        adjm[a][b] = l;
        adjm[b][a] = l;
    }

    
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    tuple<int,int,int> longest[n+5]; // dist node node
    int dist[n+5];
    memset(dist, -1, sizeof dist);
    dist[1] = 0;
    pq.push({0, 1});
    

    while (!pq.empty()){
        pair<int,int> c = pq.top(); pq.pop();
        if (dist[c.second] != c.first) continue;
        for (int i=1; i<=n; i++){
            if (adjm[c.second][i] != INT_MAX && (dist[i] == -1 || dist[i] > c.first + adjm[c.second][i])){
                dist[i] = c.first + adjm[c.second][i];
                /*
                if (adjm[c.second][i] > get<0>(longest[c.second])){
                    longest[i] = {adjm[c.second][i], c.second, i};
                } else {
                    longest[i] = longest[c.second];
                }
            */
                pq.push({dist[i], i});
            }
        }
    }

    for (int i=1; i<=n; i++){
        cout<<dist[i]<<' ';
    }

    return 0;
}   
