#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);

int n,k;
int arr[100005];

// returns the numner pf steps needed to achive k
int dp(int pos, int k){
    if(pos == n || pos==1) {
        if (k == 0) return 0;
        return 0;
    }
    return min(dp(pos+1, k-1)+arr[pos+1]-arr[pos], dp(pos-1,k-1) + arr[pos] - arr[pos-1]);
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    
    cin>>n>>k;
    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }


    
    
    return 0;
}
