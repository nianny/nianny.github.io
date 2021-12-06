#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    int n,m,x;
    cin>>n>>m>>x;

    int a,b,w;
    cin>>a>>b>>w;

    cout<<lcm(2*w,x)<<' ';

    if (lcm(w, x)/w % 2 == 1){
        cout<<lcm(w, x)<<' ';
    }
    else {
        cout<<"-1";
    }





    return 0;
}
//
//
//
//
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
// int n,m,x;
//
// int32_t main() {
//     // ifstream cin("addin.txt");
//     // ofstream cout("addout.txt");
//     kymchi;
//     cin>>n>>m>>x;
//     vector<pair<int,int>> adjList[n+5];
//
//     for (int i = 0; i<m; i++){
//         int a,b,w;
//         cin>>a>>b>>w;
//
//         // w = w % x;
//         adjList[a].push_back(make_pair(b,w));
//         adjList[b].push_back(make_pair(a,w));
//     }
//     priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq; // distance, node
//     int dist[10000];
//     memset(dist, -1, sizeof(dist));
//     pq.push(make_pair(0, source)); dist[source] = 0;
//     while(!pq.empty()){
//         pair<int,int> c = pq.top();
//         pq.pop();
//         if(c.first != dist[c.second]) continue;
//         for (auto i : adjList[c.second]) {
//             if(dist[i.first] == -1 || dist[i.first] > c.first + i.second){
//                 dist[i.first] = c.first + i.second;
//                 pq.push(make_pair(dist[i.first], i.first));
//             }
//         }
//     }
//
//
// }
//
//
// /*
// 2 1 3
// 1 2 1
// */
