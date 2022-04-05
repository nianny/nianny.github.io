#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int visited[5005];
int dist[5005];
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n;
    cin>>n;
    vector<int> arr[n+5];

    for (int i=1; i<=n; i++){
        int k;
        cin>>k;
        for (int p = 0; p<k; p++){
            int num;
            cin>>num;

            arr[num].push_back(i);
        }
    }
    int minimum = INT_MAX;
    for (int i=1; i<=n; i++){
        //i = current boss
        memset(visited, 0, sizeof(visited));
        memset(dist, 0, sizeof(dist));
        queue<int> q;
        visited[i] = true;
        dist[i] = 1;
        q.push(i);
        int sum = 0;

        while(!q.empty()){
            sum++;
            int curr = q.front();
            q.pop();
            for (auto p: arr[curr]){
                if (!visited[p]){
                    visited[p] = true;
                    dist[p] = dist[curr] + 1;
                    q.push(p);
                }
            }
        }
        if (sum == n){
            int ans = 0;
            for(int p=1; p<=n; p++){
                ans += (dist[p]);
            }
            // cout<<i<<' '<<ans<<endl;
            minimum = min(minimum, ans);
        }
    }

    cout<<minimum;
    
    
    return 0;
}

