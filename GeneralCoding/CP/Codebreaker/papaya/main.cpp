#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int r,c;
    cin>>r>>c;
    int arr[r][c];

    for (int i=0; i<r; i++){
        for (int p=0; p<c; p++){
            cin>>arr[i][p];
        }
    }

    queue<pair<int,int> > q;
    int count = 0;
    int visited[r][c];
    memset(visited, false, sizeof visited);
    q.push(make_pair(0,0));
    visited[0][0] = true;
    
    while (!q.empty()){
        pair<int,int> hi = q.front();
        q.pop();
        
        //cout<<hi.first<<' '<<hi.second<<'\n';
        count += arr[hi.first][hi.second];
        
        if(hi.first == r-1 && hi.second == c-1) break;
        pair<int,int> highest;
        int high = 0;
        for (int i=0; i<4; i++){
            int nx = hi.first + dx[i];
            int ny = hi.second + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (visited[nx][ny]) continue;
            if (arr[nx][ny] > high){
                highest = make_pair(nx,ny);
                high = arr[nx][ny];
            }
        }

        if (high != 0){
            q.push(highest);
            visited[highest.first][highest.second] = true;
        }
    }

    cout<<count;

    
    return 0;
}
