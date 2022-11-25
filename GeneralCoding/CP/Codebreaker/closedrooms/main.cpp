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
    int h,w,k;
    cin>>h>>w>>k;
    pair<int,int> source;

    char box[h+5][w+5];
    for (int i=1; i<=h; i++){
        for (int p=1; p<=w; p++){
            cin>>box[i][p];

            if (box[i][p] == 'S'){
                source = {i,p};
            }
        }
    }

    queue<pair<int,int>> q;
    int dist[h+5][w+5];
    memset(dist, -1, sizeof dist);
    
    dist[source.first][source.second] = 0;
    q.push(source);

    while(!q.empty()){
        auto c = q.front(); q.pop();

        for (int i=0; i<4; i++){
            int nx = dx[i] + c.first;
            int ny = dy[i] + c.second;

            if (nx<=0||nx>h||ny<=0||ny>w) continue;
            if (dist[nx][ny] != -1) continue;
            if (box[nx][ny] == '#') continue;

            dist[nx][ny] = dist[c.first][c.second] + 1;
            if (dist[nx][ny] >= k) continue;

            q.push({nx, ny});
        }
    }

    int mindist = INT_MAX;


    // for (int i=1; i<=h; i++){
    //     for (int p=1; p<=w; p++){
    //         cout<<dist[i][p]<<' ';
    //     }
    //     cout<<'\n';
    // }

    for (int i=1; i<=h; i++){
        for (int p=1; p<=w; p++){
            // cout<<dist[i][p]<<' ';
            if (dist[i][p] != -1){
                int hallooo;
                hallooo = min(min(i-1,p-1), min(h-i, w-p));
                // cout<<i<<' '<<p<<' '<<hallooo<<'\n';
                mindist = min(mindist, hallooo);
            }
        }
        // cout<<'\n';
    }
    // cout<<mindist<<'\n';

    if (mindist % k == 0){
        cout<< 1 + mindist/k;
    }
    else{
        cout<< 2 + mindist/k;
    }
    


    
    return 0;
}
