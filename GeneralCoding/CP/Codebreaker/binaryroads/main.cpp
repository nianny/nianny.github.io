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
    vector<int> adjList[n][2];
    
    for (int i=0; i<e; i++){
        int a,b,v;
        cin>>a>>b>>v;
        adjList[a][v].push_back(b);
        adjList[b][v].push_back(a);
    }

    queue<pair<int,int>>q;
    int dist[n][2];
    // bool visited[n][2];
    memset(dist, -1, sizeof dist);

    dist[0][0] = 0;
    
    q.push({0,0});
    

    while (!q.empty()){
        pair<int,int> c = q.front();
        q.pop();

        for (auto i: adjList[c.first][!c.second]){
            if (dist[i][!c.second] != -1) continue;

            dist[i][!c.second] = dist[c.first][c.second] + 1;
            q.push({i, !c.second});
        }
    }
    int a;
    if (dist[n-1][0] == -1 && dist[n-1][1] == -1) a = INT_MAX;
    else if (dist[n-1][0] == -1) a = dist[n-1][1];
    else if (dist[n-1][1] == -1) a= dist[n-1][0];
    else a = min(dist[n-1][0], dist[n-1][1]);
    memset(dist, -1, sizeof dist);
    dist[0][1] = 0;
    q.push({0,1});

    while (!q.empty()){
        pair<int,int> c = q.front();
        q.pop();

        for (auto i: adjList[c.first][!c.second]){
            if (dist[i][!c.second] != -1) continue;

            dist[i][!c.second] = dist[c.first][c.second] + 1;
            q.push({i, !c.second});
        }
    }
    int b = a;
    if (dist[n-1][0] == -1 && dist[n-1][1] == -1) a = INT_MAX;
    else if (dist[n-1][0] == -1) a = dist[n-1][1];
    else if (dist[n-1][1] == -1) a= dist[n-1][0];
    else a = min(dist[n-1][0], dist[n-1][1]);
    // for (int i=0; i<n; i++){
    //     cout<<dist[i][0]<<' ';
    // }
    // cout<<'\n';
    // for (int i=0; i<n; i++){
    //     cout<<dist[i][1]<<' ';
    // }
    // cout<<'\n';
    if (a == INT_MAX && b == INT_MAX) cout<< -1;
    else cout<<min(a,b);
    
    return 0;
}
