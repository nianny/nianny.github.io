#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
int n,k;
int hallo[5005][5005];

int dp(int pos, int work){
    if (hallo[pos][work] != 0) return hallo[pos][work];

    // if (pos == 0 || work == 0){
    //     return 1;
    // }
    if (work <= 0){
        return 1;
    }
    else if (pos <= 0){
        return 0;
    }

    hallo[pos][work] = 0;

    cout<<pos<<'\t'<<work<<'\t';
    for (int i=0; i<=(work/pos); i++){
        hallo[pos][work] += dp(pos-1, work - (pos-1)*i);
        // cout<<hallo[pos][work]<<'\t';
        cout<<dp(pos-1, work - (pos-1)*i)<<'\t';

    }
    cout<<'\n';



    return hallo[pos][work];
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    // int n,k;
    cin>>n>>k;
    // int dp[n+5][k+5];
    // memset(hallo, , sizeof(hallo));
    hallo[0][0] = 1;
    // for (int i=1; i<=k; i++){
    //     hallo[0][i] = 0;
    // }
    // for (int i=1; i<=n; i++){
    //     hallo[i][0] = 0;
    // }

    cout<<dp(n,k)<<'\n';

    for (int i=0; i<=n; i++){
        for (int p=0; p<=k; p++){
            cout<<hallo[i][p]<<'\t';
        }
        cout<<'\n';
    }

    cout<<dp(0,1)<<' '<<dp(1,0);



    return 0;
}


/*
  ____
/       \
|          |
\ ____ /

*/
