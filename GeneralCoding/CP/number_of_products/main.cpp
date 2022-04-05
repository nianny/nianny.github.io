#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int n;
int a[200005];
int memo_neg[200005];
int memo_pos[200005];
pair<int,int> dp (int x) {
    if (memo_neg[x] != -1){
        return make_pair(memo_neg[x], memo_pos[x]);
    }

    if (a[x] > 0){
        memo_neg[x] = dp(x-1).first;
        memo_pos[x] = dp(x-1).second + 1;
    }
    else{
        memo_neg[x] = dp(x-1).second + 1;
        memo_pos[x] = dp(x-1).first;
    }

    return make_pair(memo_neg[x], memo_pos[x]);
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    cin>>n;

    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    memset(memo_neg, -1, sizeof memo_neg);
    memset(memo_pos, -1, sizeof memo_pos);

    if (a[0] > 0){
        memo_neg[0] = 0;
        memo_pos[0] = 1;
    }
    else{
        memo_neg[0] = 1;
        memo_pos[0] = 0;
    }

    int neg = 0;
    int pos = 0;

    for (int i=0; i<n; i++){
        pair<int,int> result = dp(i);
        neg += result.first;
        pos += result.second;
    }

    cout<<neg<<' '<<pos;
    
    return 0;
}
