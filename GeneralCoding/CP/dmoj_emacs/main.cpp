#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int32_t main() {
    hallo;
    int n,m;
    cin>>n>>m;
    char arr[n][m];
    for (int i=0; i<n; i++){
        for (int p=0; p<m; p++){
            cin>>arr[i][p];
        }
    }

    bool visited[n][m];
    memset(visited, 0, sizeof visited);
    for (int i=0; i<n; i++){
        for (int p=0; p<m; p++){
            bool flag = true;
            for (int l=0; l<4; l++){
                int dx = i+dx[l];
                int dy = p+dy[l];
                if (dx <= 0 || dx >= n || dy <= 0 || dy >= m){
                    continue;
                }

            }
        }
    }
    
    
    return 0;
}
