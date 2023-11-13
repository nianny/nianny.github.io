#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int t,c,Ts,Te;
    cin>>t>>c>>Ts>>Te;

    vector<pair<int,int>> adjlist[t+1];
    int dist[t+1];
    memset(dist, -1, sizeof(dist));
    for (int i=0; i<c; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjlist[a].push_back({b,c});
        adjlist[b].push_back({a,c});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // dist, index
    pq.push({0,Ts});
    dist[Ts] = 0;

    while (!pq.empty()){
        pair<int,int> town = pq.top();
        pq.pop();
        if (dist[town.second] != town.first) continue;
        for (auto i: adjlist[town.second]){
            if (dist[i.first] == -1 || dist[i.first] > town.first + i.second){
                dist[i.first] = town.first + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }

    // for (int i=1; i<=t; i++){
    //     cout<<dist[i]<<endl;
    // }
    cout<<dist[Te]<<endl;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

