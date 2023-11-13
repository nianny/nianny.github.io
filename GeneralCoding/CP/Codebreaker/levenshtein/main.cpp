#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
string a,b;

int memo[3005][3005];
int dp(int A, int B){
    if (memo[A][B] != -1){
        return memo[A][B];
    }
    if (A == a.size()){
        return memo[A][B] = b.size() - B;
    }
    else if (B == b.size()){
        return memo[A][B] = a.size() - A;
    }

    memo[A][B] = 1e9;
    if (a[A] == b[B]){
        memo[A][B] = min(memo[A][B], dp(A+1, B+1));
    }
    memo[A][B] = min({memo[A][B], dp(A+1, B)+1, dp(A, B+1)+1, dp(A+1, B+1)+1});
    return memo[A][B];
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    memset(memo, -1, sizeof memo);
    cin>>a>>b;

    cout<<dp(0, 0)<<endl;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

