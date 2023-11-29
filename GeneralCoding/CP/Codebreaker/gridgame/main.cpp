#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int dist[1005][1005];
bool arr[1005][1005];
int ans[1000005];
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;

    int h,w,x,y,k;
    cin>>h>>w>>x>>y>>k;

    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            cin>>arr[i][j];
        }
    }
    memset(ans, -1, sizeof ans);
    memset(dist, -1, sizeof dist);

    int odd = 0, even = 0;
    dist[x][y] = 0;
    queue<pair<int,int>> q;
    if (!arr[x][y]) q.push({x,y});
    while (!q.empty()){
        const auto [X,Y] = q.front();
        q.pop();
        ans[dist[X][Y]] = max(0LL, ans[dist[X][Y]]);
        if (dist[X][Y] % 2 == 0) {
            even ++;
        }
        else odd++;

        ans[dist[X][Y]] = max(ans[dist[X][Y]], (dist[X][Y] % 2 == 0)?even:odd);


        for (int i=0; i<4; i++){
            int nx = X + dx[i];
            int ny = Y + dy[i];

            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (arr[nx][ny]) continue;
            if (dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[X][Y] + 1;

            q.push({nx, ny});
        }
    }
    if (odd == 0) even = 0;
    for (int i=1; i<=k; i++){
        if (ans[i] != -1) cout<<ans[i] << '\n';
        else {
            cout<<((i % 2 == 0)?even:odd)<<'\n';
        }
    }
    // queue<tuple<int,int,int>> q;
    // q.push({0, x, y});

    // while (!q.empty()){
    //     const auto [K, X, Y] = q.front();
    //     q.pop();
    //     for (int i=0; i<4; i++){
    //         int nx = X + dx[i];
    //         int ny = Y + dy[i];

    //         if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
    //         if (arr[nx][ny]) continue;
    //         if (K + 1 >= k) continue;

    //         q.push({K+1, nx, ny});
    //         cout<<K+1<<' '<<nx<<' '<<ny<<'\n';
    //         ans[K+1]++;
    //     }
    // }

    // for (int i=1; i<=k; i++){
    //     cout<<ans[i]<<'\n';
    // }
    
    /*
    Hallooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    */
    return 0;
}

