#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n,s;
    cin>>n>>s;

    int arr[n+5];
    int dist[n+5];
    int visited[n+5];
    memset(arr, 0, sizeof(arr));
    memset(dist, -1, sizeof(dist));
    memset(visited, 0, sizeof(visited));
    for (int i=1; i<=s; i++){
        int a,b;
        cin>>a>>b;

        arr[a] = b;
    }

    queue<int> q;
    q.push(1);
    dist[1] = 0;
    visited[1] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if (cur == n){
            break;
        }
        // cout<<cur<<endl;


        for (int i=1; i<=6; i++){
            int next = cur + i;
            
            // while(arr[next] != 0){
            //     next = arr[next];
            // }
            if (next > n){
                continue;
            }

            for(; next<= n && arr[next] != 0; next = arr[next]);


            if (next > n){
                continue;
            }


            if (visited[next]){
                continue;
            }
            q.push(next);
            visited[next] = true;
            dist[next] = dist[cur] + 1;
        }
    }

    if (dist[n] == -1){
        cout<< -1 <<endl;
    }
    else{
        cout<<dist[n]<<endl;
    }
    // cout<<dist[n]<<endl;
    
    
    return 0;
}
