#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
int n,e,k;
vector<pair<int,int>> adjList[200005];
bool visited[200005];

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    i
    cin>>n>>e>>k;

    vecto


    for (int i=1; i<=n; i++){
        int a,b,w;
        cin>>a>>b>>w;
        adjList[a].push_back(make_pair(b,w));
        adjList[b].push_back(make_pair(a, w));
    }

    queue<pair<int,int>> q;
    int dist[n];
    int ques[n];
    // memset(dist, -1, sizeof dist);

    q.push(1);
    ques[1] = 0
    dist[1] = 0
    visited[1] = true


    while(!q.empty()){
        int v = q.top()
        q.pop()

        for (auto it: adjList[v.first]){
            if (visited[it.first]) continue;
            dist[it.first] = dist[v.first] + 1;
            ques[it.first] = max(ques[v.first], )

            if (dist[it.first] <= k){
                q.push(it);
            }
        }
    }






    return 0;
}
