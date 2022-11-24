#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;

    int n;
    cin>>n;

    int a,b;
    cin>>a>>b;
    pair<int,int> source = {a,b};

    cin>>a>>b;
    pair<int,int> output = {a,b};

    int t;
    cin>>t;

    set<pair<int,int>> s;
    for (int i=0; i<t; i++){
        cin>>a>>b;
        s.insert({a,b});
    }

    int dist[n+5][n+5];
    // bool visited[n+5][n+5];
    memset(dist, -1, sizeof dist);
    // memset(visited, false, sizeof visited);

    dist[source.first][source.second] = 0;
    // visited[source.first][source.second] = true;

    queue<pair<int,int>> q;
    q.push(source);

    while (!q.empty()){
        pair<int,int> c = q.front();
        q.pop();

        if (s.find(c) != s.end()) continue;
        for (int i=0; i<8; i++){
            int nx = dx[i]+c.first;
            int ny = dy[i]+c.second;

            if (nx<=0||nx>n||ny<=0||ny>n) continue;
            if (dist[ny][ny] != -1) continue;
            // visited[nx][ny] = true;
            dist[nx][ny] = dist[c.first][c.second] + 1;
            q.push({nx,ny});
        }
    }

    // for (int i=0; i<=n; i++){
    //     for (int p=0; p<=n; p++){
    //         cout<<dist[i][p]<<' ';
    //     }
    //     cout<<'\n';
    // }

    cout<<dist[output.first][output.second];


    
    
    return 0;
}
