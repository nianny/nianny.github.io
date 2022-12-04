#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,e,m,k;
    cin>>n>>e>>m>>k;

    int M[m];
    for (int i=0; i<m; i++){
        // int a;
        cin>>M[i];
    }

    vector<pair<int,int>> adjList[n];
    for (int i=0; i<e; i++){
        int a,b,f;
        cin>>a>>b>>f;
        // adjList[a].push_back({a,f});
        adjList[b].push_back({a,f});
    }

    vector<int> potential;

    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int mindist[n];
    memset(mindist, -1, sizeof mindist);
    
    mindist[n-1] = 0;
    pq.push({0, n-1});


    while (!pq.empty()){
        auto c = pq.top(); pq.pop();

        if (c.first != mindist[c.second]) continue;

        for (auto i: adjList[c.second]){
            if (mindist[i.first] == -1 || mindist[i.first] > c.first + i.second){
                mindist[i.first] = c.first + i.second;
                pq.push({mindist[i.first], i.first});
            }
        }
    }

    



    int dist[n];
    memset(dist, -1, sizeof dist);

    dist[n-1] = 0;
    queue<int> q;
    q.push(n-1);
    // for (auto i: adjList[n-1]){
    //     cout<<i.first<<' '<<i.second<<'\n';
    // }
    while (!q.empty()){
        int c = q.front(); q.pop();
        // cout<<c<<'\n';

        for (auto i: adjList[c]){
            // cout<<i.first<<'\n';
            if (dist[i.first] != -1) continue;
            dist[i.first] = dist[c] + 1;
            q.push(i.first);
        }
    }

    // for (auto i: ans){
    //     cout<<i<<'\n';
    // }
    // int minimum = INT_MAX;
    // for (int i=0; i<n; i++){
    //     cout<<dist[i]<<' ';
    // }
    // cout<<'\n';
    // for (int i=0; i<n; i++){
    //     cout<<mindist[i]<<' ';
    // }
    // cout<<'\n';
    vector<pair<int,int>> ans;
    for (auto i: M){
        if (dist[i] >= k ){
            ans.push_back({mindist[i], i});
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.size() == 0){
        cout<< -1;
        return 0;
    }
    int minimum = ans[0].first;
    vector<int> newans;
    for (auto i: ans){
        if (i.first == minimum){
            newans.push_back(i.second);
        }
    }
    sort(newans.begin(), newans.end());
    
    
    // for (int i=0; i<n; i++){
    //     cout<<dist[i]<<' ';
    // }
    // cout<<'\n';

    // sort(newans.begin(), newans.end());

    for (auto i: newans){
        cout<<i<<' ';
    }
    if (newans.size() == 0){
        cout<< -1;
    }
    
    return 0;
}
