#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n,k;
    cin>>n>>k;

    deque<int> q;
    priority_queue<int> pq;

    for (int i=0; i<n; i++){
        int t;
        cin>>t;

        q.push_back(t);
    }
    int ans = 0;
    int indi = 0;
    while(q.size() >= 1){

        int t1 = q.front();
        q.pop_front();
        int t2 = q.front();
        q.pop_front();

        // indi += max(t1, t2);

        if (t1 > t2){
            indi += t1;
            q.push_front(t2);
        }

        else {
            indi += t2;
            q.push_front(t1);
        }

        ans = max(ans, indi);

    }
    cout<<ans;
    
    return 0;
}


/*
5 2
2 -10 2 -6 5

*/