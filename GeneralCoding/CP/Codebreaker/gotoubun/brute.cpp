#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
int n;
vector<int>arr, cop;
int memo[100010][6];
int dp(int i, int j){
    if (i < 0) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    if (j == 1) return memo[i][j] = 1;
    
    memo[i][j] = 0;

    for (int x=0; x<i; x++){
        if (arr[x] < arr[i]){
            memo[i][j] += dp(x, j-1);
            memo[i][j] %= 998244353;
        }
    }

    return memo[i][j];
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    cin>>n;
    memset(memo, -1, sizeof memo);

    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }

    // copy(arr.begin(), arr.end(), cop);
    for (int i=0; i<n; i++){
        cop.push_back(arr[i]);
    }
    sort(cop.begin(), cop.end());
    for (int i=0; i<n; i++){
        arr[i] = lower_bound(cop.begin(), cop.end(), arr[i])-cop.begin()+1;
    }

    int ans = 0;
    for (int i=0; i<n; i++){
        ans += dp(i, 5);
        ans %= 998244353;
    }
    cout<<ans;

    return 0;
}