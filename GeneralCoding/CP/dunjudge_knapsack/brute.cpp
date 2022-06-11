#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
vector<int> weight;
vector<int> value;
int memo[2001][2001];

int dp(int i, int w){
    if (memo[i][w] != -1) return memo[i][w];
    if (w < weight[i]) memo[i][w] = max(dp(i, w-1), dp(i-1, w));
    else{
        memo[i][w] = max(max(dp(i, w-1), dp(i-1, w)), dp(i-1, w-weight[i])+value[i]);
    }
    return memo[i][w];
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int s,n;
    cin>>s>>n;
    int sum = 0;
    value.push_back(0);
    weight.push_back(0);
    for (int i=0; i<n; i++){
        int v,w,k;
        cin>>v>>w>>k;
        sum += k;
        for (int p=0; p<k; p++){
            value.push_back(v);
            weight.push_back(w);
        }
    }
    memset(memo, -1, sizeof memo);
    for (int i=1; i<=sum; i++){
        memo[i][0] = 0;
    }
    for (int i=0; i<sum; i++){
        memo[0][i] = 0;
    }
    // cout<<sum<<' '<<s<<' ';
    cout<<dp(sum, s);

    // for (int i=0; i<20; i++){
    //     for (int p=0; p<20; p++){
    //         cout<<memo[i][p]<<' ';
    //     }
    //     cout<<endl;
    // }


    return 0;
}

/*
15 5
4 12 1
2 1 1
10 4 1
1 1 1
2 2 1
*/

/*
20 3
5000 15 1
100 1 3
50 1 4
*/