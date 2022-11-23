#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int32_t main() {
    int n=rng()%10+1;
    int l=rng()%100+1;
    int t=rng()%l+1;

    cout<<n<<' '<<l<<' '<<t<<'\n';
    for(int i=0; i<n; i++){
        cout<<rng()%l<<' ';
    }
}