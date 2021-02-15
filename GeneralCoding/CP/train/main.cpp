#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int arr[10010];
int memo[10010];

int dp (int index){
    //cout<<"HI";
    if (memo[index] >= 0){
        return memo[index];
    }
    int ans = 1e9+10;
    if (index == n+1){
        ans = 0;
    }
    //memo[index] = 1e9;
    for (int i=index+1; i<n+2; i++){
        if (arr[i] <= arr[index]){
            //cout<<index<<' '<<i<<'\n';
            ans = min(ans, dp(i)+(i-index)*(i-index));
        }
    }
    //cout<<index<<' '<<ans<<'\n';

    return memo[index] = ans;
}

int32_t main() {
    
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    //cout<<"Start";
    memset(memo, -1, sizeof(memo));
    //memo[n+1]=0;
    cin>>n;
    //cout<<n<<' ';
    arr[0] = 1e9;
    arr[n+1] = 0;
    for (int i=1; i<n+1; i++){
        cin>>arr[i];
    }
    // for (int i=0; i<n+2; i++){
    //     cout<<arr[i]<<' ';
    // }
    //cout<<'\n';
    //cout<<"Read \n";

    cout<<dp(0);
    
    return 0;
}