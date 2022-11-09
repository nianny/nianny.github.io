#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int x_c[] = {0, 0, 1, -1};
int y_c[] = {1, -1, 0, 0};

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
    int count = 0;
    for (int i=0; i<n; i++){
        for (int p=0; p<m; p++){
            bool flag = true;
            for (int l=0; l<4; l++){
                int dx = i+x_c[l];
                int dy = p+y_c[l];
                if (dx < 0 || dx >= n || dy < 0 || dy >= m){
                    continue;
                }
                if (visited[dx][dy] == true){
                    flag = false;
                    break;
                }
            }
            if (arr[i][p] == '*'){
                visited[i][p] = true;
                if (flag){
                    count++;
                    // cout<<i<<' '<<p<<' '<<endl;
                }
            }
        }
    }

    cout<<count;
    
    
    return 0;
}
