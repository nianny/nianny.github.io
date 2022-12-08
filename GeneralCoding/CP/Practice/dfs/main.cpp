#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int R,C;
char box[110][110];
bool visited[110][110];

void dfs(int x, int y){
    // if (visited[x][y]) return;
    for (int i=0; i<4; i++){
        int nx = dx[i] + x;
        int ny = dy[i] + y;

        if (nx < 0||nx>=R||ny<0||ny>=C) continue;
        if (visited[nx][ny]) continue;
        if (box[nx][ny] == '.') continue;
        visited[nx][ny] = true;
        dfs(nx, ny);
    }

}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    
    cin>>R>>C;
    for (int i=0; i<R; i++){
        for (int p=0; p<C; p++){
            cin>>box[i][p];
        }
    }
    int count = 0;
    for (int i=0; i<R; i++){
        for (int p=0; p<C; p++){
            if (!visited[i][p] && box[i][p] == 'H'){
                // cout<<i<<' '<<p<<'\n';
                count++;
                dfs(i,p);
            }
        }
    }
    cout<<"Oh, bother. There are "<<count<<" pools of hunny.";
    
    return 0;
}
