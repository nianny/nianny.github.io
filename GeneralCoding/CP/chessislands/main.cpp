#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n,e;
    cin>>n>>e;
    int size[n+5];
    vector<int> links[n+5];
    for (int i=1; i<=n; i++){
        cin>>size[i];
    }
    int a,b;
    for (int i=0; i<e; i++){
        cin>>a>>b;
        links[a].push_back(b);
        links[b].push_back(a);
    }

    int ans = 0;
    bool visited[n+5];
    memset(visited,0,sizeof visited);
    queue<int>q;
    // visited[1] = 1;
    // q.push(1);
    bool colour[n+5];
    // colour[1] = 1;
    memset(colour, 0, sizeof colour);
    vector<int> white, black;
    for (int i=1; i<= n; i++){
        // cout << colour[i] << ' ';
        if (visited[i]) continue;
        
        visited[i] = 1;
        q.push(i);
        colour[i] = 0;
        int c1 = 0;
        int c2 = 0;
        // white.push_back(i);
        while (!q.empty()){
            int v = q.front(); q.pop();
            if (colour[v]){
                c1 += size[v];
                white.push_back(v);
            }
            else {
                c2 += size[v]; 
                black.push_back(v);
            }

            bool indi = !colour[v];

            for (auto b:links[v]){
                if (visited[b]) continue;

                colour[b] = indi;
                q.push(b);
                visited[b] = 1;
            }
        }
        // int c1 = 0;
        // int c2 = 0;
        // for (int i=1; i<=n; i++){
        //     if (colour[i]){
        //         c1 += size[i];
        //     }
        //     else{
        //         c2 += size[i];
        //     }
        // }

        
        ans += min(c1,c2);
    //      for (auto i: white) cout << i << ' ';
    // cout << '\n';
    // for (auto i: black) cout << i << ' ';
        // cout<<c1<<' '<<c2<<'\n';
    }
    // int 
    // for (int i=1; i<= n; i++){

    // }

    
    cout<<ans << '\n';
    // for (auto i: white) cout << i << ' ';
    // cout << '\n';
    // for (auto i: black) cout << i << ' ';
    // cout<<' '<<c1<<' '<<c2;
    // cout<<'\n';

    // for (int i=1; i<=n; i++){
    //     cout << size [i]<<' ';
    // }


    //start bfs




    return 0;
}