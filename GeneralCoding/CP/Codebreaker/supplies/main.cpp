#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,e,h,t;
    cin>>n>>e>>h>>t;

    vector<pair<int,int> > adjList[n];
    for (int i=0; i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;

        adjList[a].push_back({b,c});  
    }
    int dist[n];
    memset(dist, -1, sizeof dist);
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    dist[h] = 0;
    pq.push({0, h});

    while (!pq.empty()){
        pair<int,int> c = pq.top(); pq.pop(); //distance, node
        if (c.first != dist[c.second]) continue;
        for (auto i: adjList[c.second]){
            if (dist[i.first] == -1 || dist[i.first] > c.first + i.second){
                dist[i.first] = c.first + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }


    int dist1[n];
    memset(dist1, -1, sizeof dist1);
    dist1[t] = 0;
    pq.push({0, t});

    while (!pq.empty()){
        pair<int,int> c = pq.top(); pq.pop();
        if(c.first != dist1[c.second]) continue;
        for (auto i: adjList[c.second]){
            if (dist1[i.first] == -1 || dist1[i.first] > c.first + i.second){
                dist1[i.first] = c.first + i.second;
                pq.push({dist1[i.first], i.first});
            }
        }
    }

    
    if (dist[t] == -1 || dist1[h] == -1){
        cout<<-1;
    } else{
        cout<<dist[t] + dist1[h];
    }
    
    return 0;
}
