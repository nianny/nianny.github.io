#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl "\n"


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    int n,k;
    cin>>n>>k;

    priority_queue<int> pq;
    queue<int> q;

    for (int i=0; i<k; i++) {
        int x;
        cin>>x;
        pq.push(x);
    }

    for (int i=0; i<n-k; i++) {
        int x;
        cin>>x;
        q.push(x);
    }
    int ans = 0;
    int indi = 0;
    while (!pq.empty()) {
        indi += pq.top();
        pq.pop();

        if (!q.empty()) {
            pq.push(q.front());
            q.pop();
        }

        ans = max(ans, indi);
    }  

    cout<<ans<<endl;
    
    return 0;
}