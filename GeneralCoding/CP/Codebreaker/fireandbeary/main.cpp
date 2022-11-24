#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    
    int r,c;
    cin>>r>>c;
    char arr[r+5][c+5];
    pair<int,int> flame;
    pair<int,int> bear;
    for (int i=1; i<=r; i++){
        for (int p=1; p<=c; p++){
            cin>>arr[i][p];
            if (arr[i][p] == 'F') flame = {i,p};
            if (arr[i][p] == 'B') bear = {i,p};
        }
    }

    int flame_time[r+5][c+5];
    int bear_time[r+5][c+5];
    memset(flame_time, -1, sizeof flame_time);
    memset(bear_time, -1, sizeof bear_time);
    
    queue<pair<int,int>> q;

    // flame
    q.push(flame);
    flame_time[flame.first][flame.second] = 0;
    while (!q.empty()){
        pair<int,int> f = q.front();
        q.pop();
        
        for (int i=0; i<4; i++){
            int nx = f.first + dx[i];
            int ny = f.second + dy[i];

            if (nx<0||nx>r+1||ny<0||ny>c+1) continue;
            if (flame_time[nx][ny] != -1) continue;
            flame_time[nx][ny] = flame_time[f.first][f.second] + 1;
            q.push({nx, ny});
        }
    }

    bear_time[bear.first][bear.second] = 0;
    q.push(bear);
    while (!q.empty()){
        pair<int,int> f = q.front(); q.pop();

        if (arr[f.first][f.second] == '@') continue;
        for (int i=0; i<4; i++){
            int nx = dx[i] + f.first;
            int ny = dy[i] + f.second;
            // cout<<nx<<' '<<ny<<'\n';
            if (nx < 0 || nx > r+1 || ny < 0 || ny > c+1) continue;
            if (bear_time[nx][ny] != -1) continue;

            bear_time[nx][ny] = bear_time[f.first][f.second] + 2;
            q.push({nx, ny});
        }
    }

    // for (int i=0; i<=r+1; i++){
    //     for (int p=0; p<=c+1; p++){
    //         cout<<flame_time[i][p]<<' ';
    //     }
    //     cout<<'\n';
    // }
    // for (int i=0; i<=r+1; i++){
    //     for (int p=0; p<=c+1; p++){
    //         cout<<bear_time[i][p]<<' ';
    //     }
    //     cout<<'\n';
    // }

    vector<int>v;
    // check vertical
    for (int i=1; i<=r; i++){
        if (bear_time[i][0] < flame_time[i][0]) v.push_back(bear_time[i][0]);
        if (bear_time[i][c+1] < flame_time[i][c+1]) v.push_back(bear_time[i][c+1]);
    }

    for (int i=1; i<=c; i++){
        if (bear_time[0][i] < flame_time[0][i]) v.push_back(bear_time[0][i]);
        if (bear_time[r+1][i] < flame_time[r+1][i]) v.push_back(bear_time[r+1][i]);
    }


    sort(v.begin(), v.end());
    if(v.size() <= 0) cout<< -1;
    else cout<<v[0];

    return 0;
}
