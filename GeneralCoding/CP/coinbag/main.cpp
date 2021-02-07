#include <bits/stdc++.h>
using namespace std;
#define int long long

bool compare(pair<int,int> lhs, pair<int,int> rhs){
    // if (lhs.second == rhs.second){
    //     return lhs.first < rhs.first;
    // }
    // else {
    //     return lhs.second > rhs.second;
    // }
    if (lhs.first == 0 or rhs.second == 0){
        return true;
    }
    else if (lhs.second == 0 or rhs.first == 0){
        return false;
    }
    return (lhs.second/lhs.first) >= (rhs.second/rhs.first);
}
int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 

    int n,m;
    cin>>n>>m;
    pair<int,int>coins[n];
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;

        coins[i] = make_pair(a,b);
    }

    sort (coins, coins + n, compare);

    // for (int i=0; i<n; i++){
    //     cout<<coins[i].first<<' '<<coins[i].second<<'\n';
    // }
    // cout<<'\n';

    int sum = 0;
    int ans = 0;
    for (int i=0; i<n; i++){
        ans += coins[i].second;
        sum += coins[i].first;



        if (sum > m){
            ans -= coins[i].second;
            sum -= coins[i].first;

            continue;
        } 
    }

    cout<<ans;

    return 0;
}