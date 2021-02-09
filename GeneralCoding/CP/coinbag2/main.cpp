#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int>coins[510];
//int table[510][510];
int dp (int i, int w){
    if (w <= 0){
        return 0;
    }
    else if (i<0){
        return 0;
    }
    return max(dp(i, w-1), dp(i-1, w), dp(i, w-coins[i].first)+coins[i].second);
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

    cout<<dp(n-1,m);
    return 0;
}