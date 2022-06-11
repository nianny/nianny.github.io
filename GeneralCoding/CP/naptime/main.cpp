#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool comp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,m,r,c;
    cin>>n>>m>>r>>c;

    pair<int,int> arr[n+5];
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr[i] = make_pair(a,b);
    }

    queue<pair<int,int>> q;
    int grid[r+5][c+5];
    memset(grid, -1, sizeof grid);


    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        q.push(make_pair(a,b));
        grid[a][b] = 0;
    }
    
    int count[r+c+5];
    memset(count, 0, sizeof count);
    while(!q.empty()){
        pair<int,int> cur = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx>=1 && nx<=r && ny>=1 && ny<=c && grid[nx][ny]==-1){
                grid[nx][ny] = grid[cur.first][cur.second] + 1;
                count[grid[nx][ny]]++;
                q.push(make_pair(nx,ny));
            }
        }
    }
    
    sort(arr, arr+n, comp);
    for(int i=0; i<n; i++){
        cout<<arr[i].first<<' '<<arr[i].second<<'\n';
    }
    int ans = 0;
    for (int i=0; i<r+c; i++){
        if (count[i]==0) continue;
        for (int j=0; j<n; j++){
            if (arr[j].first <= i && arr[j].second >= i and count[i] > 0){
                count[i] --;
                ans ++;
            }
        }
    }

    cout<<ans;




    
    
    return 0;
}
/*
4 2 2 4
0 0
2 2
1 2
3 4
1 1
1 3
*/