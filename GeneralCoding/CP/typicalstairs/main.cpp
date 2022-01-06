#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'

int n,m;
bool broken[100005];
int dp[100005];



int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    cin>>n>>m;

    for (int i=0; i<m; i++){
        int a;
        cin>>a;

        broken[a] = true;
    }

    dp[0] = 1;
    // dp[1] = 1;

    if (broken[1]){
        dp[1] = 0;
    }
    else{
        dp[1] = 1;
    }

    for (int i=2; i<=n; i++){
        if (broken[i]){
            dp[i] = 0;
        }
        else{
            dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
        }
    }

    cout<<dp[n]<<endl;


    
    return 0;
}
