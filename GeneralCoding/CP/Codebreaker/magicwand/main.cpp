#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int h,w,x,y,t;
    cin>>h>>w>>x>>y>>t;
    int arr[h+5][w+5];
    for (int i=1; i<=h; i++){
        for (int j=1; j<=w; j++){
            cin>>arr[i][j];
        }
    }

    int source = arr[x][y];

    queue<pair<int,int>> q;
    int ans[h+5][w+5];
    bool visited[h+5][w+5];
    memset(ans, 0, sizeof ans);
    memset(visited, false, sizeof visited);

    q.push({x,y});
    ans[x][y] = 1;

    while (!q.empty()){
        pair<int,int> c = q.front();
        q.pop();

        for (int i=0; i<4; i++){
            int nx = dx[i]+c.first;
            int ny = dy[i]+c.second;
            if (nx<=0||nx>h||ny<=0||ny>w) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            if (abs(arr[nx][ny]-source) <= t){
                ans[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }

    for (int i=1; i<=h; i++){
        for (int j=1; j<=w; j++){
            cout<<ans[i][j];
        }
        cout<<'\n';
    }


    
    return 0;
}
