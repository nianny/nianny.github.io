#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
priority_queue<pii, vector<pii>, greater<pii>> pq;
int nums[2000001];
main(){
    int n; cin >> n;
    int d, c;
    while (n--){
        cin >> d >> c;
        pq.push({d, c});
        nums[d]++;
    }
    int ans = 0;
    while (!pq.empty()){
        int lvl, c;
        tie(lvl, c) = pq.top();
        pq.pop();
        if (nums[lvl] == 1) continue;
        int nlvl, nc;
        tie(nlvl, nc) = pq.top();
        pq.pop();
        ans += c + nc;
        pq.push({lvl + 1, c + nc});
        nums[lvl] -= 2;
        nums[lvl + 1]++;
    }
    cout << ans << endl;
}