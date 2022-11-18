#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,e;
    cin>>n>>e;

    vector<pair<int,int> > adjlist[n];

    for (int i=0; i<e; i++){
        int a,b,f;
        cin>>a>>b>>f;

        adjlist[a].push_back({b,f});
        adjlist[b].push_back({a,f});
    }

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    int dist0[n+5];
    memset(dist0, -1, sizeof(dist0));
    dist0[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        pair<int,int> c = pq.top(); pq.pop();
        if (c.first != dist0[c.second]) continue;
        for (auto i: adjlist[c.second]){
            if (dist0[i.first] == -1 || dist0[i.first] > c.first + i.second){
                dist0[i.first] = c.first + i.second;
                pq.push(make_pair(dist0[i.first], i.first));
            }
        }
    }

    int dist1[n+5];
    memset(dist1, -1, sizeof(dist1));
    dist1[n-1] = 0;
    pq.push({0, n-1});

    while(!pq.empty()){
        pair<int,int> c = pq.top(); pq.pop(); // distance, node
        if (c.first != dist1[c.second]) continue;
        for (auto i: adjlist[c.second]){
            if (dist1[i.first] == -1 || dist1[i.first] > dist1[i.second] + c.first){
                dist1[i.first] = dist1[i.second] + c.first;
                pq.push({dist1[i.first], i.first});
            }
        }
    }
    
    for (int i=0; i<n; i++){
        cout<<dist0[i]<<'n';
    }
    cout<<'\n';
    int k;
    cin>>k;

    for (int i=0; i<k; i++){
        int x,y;
        cin>>x>>y;

        int cur1 = dist0[x] + dist1[y];
        int cur2 = dist0[y] + dist1[x];
        int ans = LLONG_MAX;
        if (dist0[x] != -1 && dist1[y] != -1){
            ans = min(ans, cur1);
        }
        if (dist1[y] != -1 && dist0[x] != -1){
            ans = min(ans, cur2);
        }

        if ((dist0[n-1] - ans - 1)>=0){
            cout<<dist0[n-1]-ans-1<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }
    
    return 0;
}
