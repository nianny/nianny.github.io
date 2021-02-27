#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
// int dp(int ind, int num){
//     if (ind == n-1){
//         return 1;
//     }
//     else if (ind >= n-1){
//         return 0;
//     }
//     int sum;
//     if (num >= k-1){
//         return dp(ind+2, num)%998244353;
//     }
//     return (dp(ind+1,num+1) + dp(ind+2,num))%998244353;
// }

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    cin>>n>>k;
    //cout<<dp(-1,0);
    int arr[n+5];
    memset(arr,0,sizeof(arr));
    arr[0]=1;

    for (int i=1; i<=n+1; i++){
        for (int p = i-k; p<i; p++){
            if (p<0){
                continue;
            }
            arr[i] += arr[p]%998244353;
        }
        arr[i]%=998244353;
    }
    cout<<arr[n+1];
    return 0;
}