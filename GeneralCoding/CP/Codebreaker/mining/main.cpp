#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};



int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int r,c,k;
    cin>>r>>c>>k;

    char a[r][c];
    pair<int,int> s; //start
    pair<int,int> e; //end
    for (int i=0; i<r; i++){
        for (int y=0; y<c; y++){
            cin>>a[i][y];
            if (a[i][y] == 'S'){
                s = {i,y};
            }
            if (a[i][y] == 'E'){
                e = {i,y};
            }
        }
    }

    int dist[r][c][k+5];
    memset(dist, -1, sizeof dist); //number of steps needed to reach r,c with k durability left
    dist[s.first][s.second][k] = 0;
    // queue<pair<int,int>> q;
    // q.push(s);


    queue<tuple<int,int,int>> q;
    q.push({s.first, s.second, k});    
    while (!q.empty()){
        const auto [x,y,K] = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (a[nx][ny] == 'B') continue;
            if (K-((a[nx][ny] == 'W')?1:0) < 0) continue;
            if (dist[nx][ny][K-((a[nx][ny] == 'W')?1:0)] != -1) continue;
            dist[nx][ny][K-(a[nx][ny] == 'W'?1:0)] = dist[x][y][K] + 1;
            q.push({nx,ny,K-((a[nx][ny] == 'W')?1:0)});
            // cout<<x<<' '<<y<<' '<<K<<' '<<nx<<' '<<ny<<' '<<K-((a[nx][ny] == 'W')?1:0)<<'\n';
        }
    }
    // for (int i=0; i<r; i++){
    //     for (int j=0; j<c; j++){
    //         cout<<dist[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // cout<<'\n';
    // for (int i=0; i<r; i++){
    //     for (int j=0; j<c; j++){
    //         cout<<dist2[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    // cout << dist2[e.first][e.second] << endl;

    // for (int i=0; i<=k; i++){
    //     cout<<i<<'\n';
    //     for (int j=0; j<r; j++){
    //         for (int l=0; l<c; l++){
    //             cout<<dist[j][l][i]<<' ';
    //         }
    //         cout<<'\n';
    //     }
    // }
    int ans = 1e9;
    for (int i=0; i<=k; i++){
        if (dist[e.first][e.second][i] != -1){
            ans = min(ans, dist[e.first][e.second][i]);
        }
    }

    if (ans == 1e9){
        cout<< -1;
    }
    else {
        cout<<ans;
    }
    /*
    Hallooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    */
    return 0;
}

