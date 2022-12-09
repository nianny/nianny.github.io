#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n,m;
int arr[45];
unordered_map<int,int> ans[45];
int dp(int remaining, int index){
    if (ans[index].find(remaining) != ans[index].end()) return ans[index][remaining];
    // cout<<remaining<<' '<<index<<'\n';
    if (remaining < 0){
        // cout<<remaining<<' '<<index<<' '<<1<<'\n';
        return 0;
    }
    if (index >= n) return 1;
    else{
        // cout<<remaining<<' '<<index<<' '<<dp(remaining, index+1) + dp(remaining-arr[index], index+1)<<'\n';
        return ans[index][remaining] = dp(remaining, index + 1) + dp(remaining-arr[index], index+1);
    }
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    cin>>n>>m;
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<dp(m, 0)<<'\n';
    // cout<<dp(1100,0)<<'\n';
    return 0;
}
