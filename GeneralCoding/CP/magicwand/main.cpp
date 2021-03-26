#include <bits/stdc++.h>
using namespace std;
#define int long long
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int h,w,x,y,t;
    cin>>h>>w>>x>>y>>t;
    int value[h][w];
    x--;
    y--;
    cout<<h<<' '<<w<<'\n';
    for (int i=0; i<h; i++){
        for (int p=0; p<w; p++){
            cin>>value[i][p];
        }
    }

    queue<pair<int,int>>q;
    int ans[h][w];
    memset(ans, 0, sizeof ans);
    bool visited[h][w];
    memset(visited,false,sizeof visited);
    q.push(make_pair(x,y));

    while (!q.empty()){
        pair<int,int>hallo = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = hallo.first + dx[i];
            int ny = hallo.second + dy[i];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

            if (abs(value[nx,ny] - value[x,y]) <= t){
                q.push(make_pair(nx,ny));
                ans[nx][ny] = 1;
            }
        }

    }

    for (int i=0; i<h; i++){
        for (int p = 0; p<w; p++){
            cout<<ans[i][p]<<' ';
            
        }
        cout<<'\n';
    }

    return 0;
}