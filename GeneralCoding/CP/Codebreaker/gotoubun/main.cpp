#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
vector<int>arr, cop;
int dp[5][100010];
int fen[100010];
int n;
int MOD = 998244353;
void update(int X, int V){
    while (X <= 5){
        // cout<<X<<' '<<X % -X<<' '<<V<<'\n';
        fen[X] += V;
        fen[X] %= MOD;
        X += (X & -X);
    }
}

int query(int R){
    int result = 0;

    while (R){
        result += fen[R];
        result %= MOD;
        R -= R & -R;
    }

    return result;
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    
    cin>>n;
    // cout<<n<<'\n';

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

    // for (auto i: arr){
    //     cout<<i<<' ';
    // }

    for (int i=0; i<n; i++){
        dp[1][i] = 1;
    }
    for (int i=2; i<=5; i++){
        for (int p=0; p<n; p++){
            dp[i][p] = query(arr[p]-1);
            cout<<i<<' '<<p<<' '<<dp[i][p]<<'\n';
            update(arr[p], dp[i-1][p]);
        }
        for (int p=0; p<=n; p++){
            fen[p] = 0;
        }  
        cout<<i<<'\n';
        for (int p=0; p<n; p++){
            cout<<dp[i][p]<<' ';
        }
        cout<<'\n';
    }

    cout<<'\n'<<'\n';
    for (int i=0; i<=5; i++){
        for (int p=0; p<n; p++){
            cout<<dp[i][p]<<' ';

        }
        cout<<'\n';
    }

    int ans = 0;
    for (int i=0; i<n; i++){
        cout<<i<<' '<<dp[5][i]<<'\n';
        ans += dp[5][i];
        ans %= MOD;
    }

    cout<<ans;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    一剪寒梅傲立雪中
    只为伊人飘香
    */
    return 0;
}

