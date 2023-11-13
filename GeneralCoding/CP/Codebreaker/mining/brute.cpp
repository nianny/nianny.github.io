#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
class cmp {
    public:
        bool operator() (tuple<int,int,int> a, tuple<int,int,int> b){
            return get<0>(a) > get<0>(b);
        }
};

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

    int dist[r][c];
    int dist2[r][c];
    memset(dist, -1, sizeof dist);
	memset(dist2, -1, sizeof dist2);
    dist[s.first][s.second] = 0;
	dist2[s.first][s.second] = 0;
    // queue<pair<int,int>> q;
    // q.push(s);

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, cmp> q;
    q.push({0,s.first, s.second});

    while (!q.empty()){
        const auto [v, x, y] = q.top();
        q.pop();
        if (v != dist[x][y]) continue;
        for (int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (a[nx][ny] == 'B') continue;
            if (dist[nx][ny] != -1) continue;

            if ((dist[x][y] + (a[nx][ny] == 'W' ? 1 : 0) <= k) && (dist[nx][ny] == -1 || dist[nx][ny] > dist[x][y] + (a[nx][ny] == 'W' ? 1 : 0))){
                dist[nx][ny] = dist[x][y] + (a[nx][ny] == 'W' ? 1 : 0);
                // dist2[nx][ny] = dist2[x][y]+1;
                q.push({dist[nx][ny], nx, ny});
            }
        }
    }

    queue<pair<int,int>> q2;
    memset(dist2, -1, sizeof dist2);
    dist2[s.first][s.second] = 0;
    q2.push(s);    
    while (!q2.empty()){
        pair<int,int> cur = q2.front();
        q2.pop();
        for (int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (dist2[nx][ny] != -1) continue;
            if (dist[nx][ny] == -1) continue;
            dist2[nx][ny] = dist2[cur.first][cur.second]+1;
            q2.push({nx,ny});
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

    cout << dist2[e.first][e.second] << endl;
    /*
    Hallooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    */
    return 0;
}

