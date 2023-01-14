#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int r,c;
int zao, shang, hao;
char arr[1010][1010];
bool visited[1010][1010];
bool non_visited[1010][1010];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int sx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int sy[] = {0, 1, 1, 1, 0, -1, -1, -1};
void non_dfs(int x, int y){
    // cerr<<x<<' '<<y<<'\n';
    stack<pair<int,int>>s;
    s.push({x,y});
    
    while(!s.empty()){
        pair<int,int> a = s.top();
        s.pop();
        for (int i=0; i<8; i++){
            int nx = a.first + sx[i];
            int ny = a.second + sy[i];
            // cerr<<nx<<' '<<ny<<' '<<arr[nx][ny]<<' '<<non_visited[nx][ny]<<'\n';

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (arr[nx][ny] != '0' || non_visited[nx][ny]) continue;
            non_visited[nx][ny] = true;
            // non_dfs(nx, ny);
            s.push({nx, ny});
        }
    }
    
}
int dfs(int x, int y){
    int ans = 0;

    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        // if (nx == p.first && ny == p.second) continue;
        if (visited[nx][ny]) continue;
        if (arr[nx][ny] != '1'){
            if(!non_visited[nx][ny]){
                ans++;
                non_visited[nx][ny] = true;
                non_dfs(nx, ny);
            }
        }
        else{
            visited[nx][ny] = true;
            ans += dfs(nx, ny);
        }
        // if(visited[nx][ny]) {
        //     ans ++;
        //     continue;
        // }

        
    }

    return ans;
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    cin>>r>>c;


    for (int x=0; x<r; x++){
        for (int y=0; y<c; y++){
            cin>>arr[x][y];
        }
    }
    // for (int x=0; x<r; x++){
    //     for (int y=0; y<c; y++){
    //         cout<<arr[x][y];
    //     }
    //     cout<<'\n';
    // }

    // return 0;

    //x = 0;
    // bool flag = true;
    for (int y=0; y<c; y++){
        int cur = 0;
        if(arr[cur][y] == '0' && !non_visited[cur][y]){
            non_visited[cur][y] = true;
            // flag = false;
            non_dfs(cur, y);
        }

        cur = r-1;
        if(arr[cur][y] == '0' && !non_visited[cur][y]){
            non_visited[cur][y] = true;
            // flag = false;
            non_dfs(cur, y);
        }
    }

    for (int x=0; x<r; x++){
        int cur = 0;
        if (arr[x][cur] == '0' && !non_visited[x][cur]){
            non_visited[x][cur] = true;
            non_dfs(x, cur);
        }
        cur = c-1;
        if (arr[x][cur] == '0' && !non_visited[x][cur]){
            non_visited[x][cur] = true;
            non_dfs(x, cur);
        }
    }

    // if (flag) return 1;

    // return 0;

    for (int x=0; x<r; x++){
        for (int y=0; y<c; y++){
            if (arr[x][y] == '0' || visited[x][y]) continue;
            visited[x][y] = true;
            int count = dfs(x,y);
            if (count == 2) zao++;
            else if (count == 1) hao++;
            else {
                shang++;
                // cout<<x<<' '<<y<<'\n';
            }
            // cout<<count<<'\n';
        }
    }

    shang -= hao;

    cout<<zao<<' '<<shang<<' '<<hao<<'\n';

    
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

