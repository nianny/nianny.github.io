#include <bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int>coins[510];
int n,m;
int table[510][510];
int dp (int i, int w){
    //cout<<i<<' '<<w<<'\n';
    if (table[i][w] != -1) return table[i][w];
    if (i == n){
        return 0;
    }
    int sum = 0;
    if (w >= coins[i].first){
        sum = max(sum, dp(i+1, w-coins[i].first)+coins[i].second);
    }

    sum = max(sum, dp(i+1, w)); 

    table[i][w] = sum;
    return table[i][w];

    //cout<<'\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
    memset(table, -1, sizeof(table));
    cin>>n>>m;
    //pair<int,int>coins[n];
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;

        coins[i] = make_pair(a,b);
    }

    cout<<dp(0,m);
    return 0;
}