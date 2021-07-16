#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);

int n,k;
int arr[10005];
int dp[10005][105];

int dep(int index, int sum){
    if (index == 0 && sum != 0) return 0;
    if (index == 0 && sum == 0) return 1;
    if (dp[index][sum] != -1) return dp[index][sum];
    dp[index][sum] = dep(index-1, (k+sum+arr[index])%k) || dep(index-1, (k+sum-arr[index])%k);
    // cout<<index<<' '<<sum<<' '<<dp[index][sum]<<endl;
    return dp[index][sum];
}

int32_t main() {
    kymchi;

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];arr[i]%=k;
    }

    // memset(arr, -1, sizeof(arr));
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;

    cout<<(dep(n, 0) == 1 ? "Divisible" : "Not divisible");




    
    return 0;
}