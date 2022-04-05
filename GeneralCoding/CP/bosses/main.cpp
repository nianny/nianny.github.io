#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int visited[5005];
int dist[5005];
vector<int> child[5005];

int dfs(int x){
    if (child[x].size() == 0){
        return 1;
    }

    int sum = 0;
    cout<<x<<' ';
    for (auto i: child[x]){
        sum += dfs(i)*2;
        // cout<<i<<" ";
    }
    // cout<<endl;

    return sum;
}

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
        // vector<int> backup[5005];
        // child = backup;
        visited[i] = true;
        dist[i] = 0;
        q.push(i);

        vector<int> v[n+5];

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            vector<int>hallo;
            for (auto p: arr[curr]){
                if (!visited[p]){
                    hallo.push_back(p);
                    visited[p] = true;
                    dist[p] = dist[curr] + 1;
                    q.push(p);
                }
            }

            child[curr] = hallo;
        }
        cout<<i<<endl;
        int ans = dfs(i);
        // for(int p=1; p<=n; p++){
        //     ans += (dist[p]+1);
        // }
        // cout<<i<<' '<<ans<<endl;
        cout<<endl;
        for (int p=1; p<=n; p++){
            cout<<p<<' ';
            for(auto j: child[p]){
                cout<<j<<' ';
            }
            cout<<endl;
        }
        cout<<ans<<endl<<endl;


        minimum = min(minimum, ans);
    }

    cout<<minimum;
    
    
    return 0;
}
