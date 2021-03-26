#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>>adjList[n];
    for (int i=0; i<e; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adjList[a].push_back(make_pair(b,c));

    }

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

    int dist[n];
    int count[n];
    memset(count, 0, sizeof(count));
    memset(dist, -1, sizeof(dist));
    pq.push(make_pair(0, 0)); dist[0] = 0; count[0] = 1;
    while(!pq.empty()){
        pair<int,int> c = pq.top();
        pq.pop();
        if(c.first != dist[c.second]) continue;
        for (auto i:adjList[c.second]) {
            //iterate every connected node

            if(dist[i.first] == -1 || dist[i.first] > c.first + i.second){
                dist[i.first] = c.first + i.second;
                pq.push(make_pair(dist[i.first], i.first));
                count[i.first] = count[c.second];
                count[i.first] %= 1000000007;
            }
            else if (dist[i.first] ==( c.first + i.second)){
                count[i.first] += count[c.second];
                count[i.first] %= 1000000007;
            }
        }
    }
    cout<<count[n-1]%1000000007;

    return 0;
}