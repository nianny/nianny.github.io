#include <bits/stdc++.h>
using namespace std;
#define int long long
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};


int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    
    int m,n,s;
    cin>>m>>n>>s;
    vector<pair<int,int>> points;

    //cout<<'\n';

    for (int i=0; i<s; i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        //cout<<a<<' '<<b<<'\n'<<'\n';
        points.push_back(make_pair(a,b));
    }

    //cout<<"HI \n \n \n";


    bool visited[m][n];
    int dist[m][n];
    queue<pair<int,int>>q;
    memset(visited, 0, sizeof(visited));
    memset(dist,0,sizeof(dist));
    for (pair<int,int> p: points){
        //cout<<p.first<<' '<<p.second<<'\n';
        visited[p.first][p.second] = 1;
        dist[p.first][p.second] = 0;
        q.push(make_pair(p.first, p.second));
    }

    while (!q.empty()){
        pair<int,int> v = q.front(); q.pop();
        int x = v.first;
        int y = v.second;

        // for (auto i: points[v.first][v.second]) {
        //     if (visited[])
        // }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (visited[nx][ny]) continue;

            q.push(make_pair(nx,ny));
            visited[nx][ny] = 1;
            dist[nx][ny] = dist[x][y]+1;


        }
    }

    int ans = 0;
    for (int i=0; i<m; i++){
        for (int p=0; p<n; p++){
            ans = max(ans, dist[i][p]);
        }
        
    }
    ans++;
    cout<<ans;




    return 0;
}