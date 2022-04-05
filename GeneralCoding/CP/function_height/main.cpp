#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    int n,k;
    cin>>n>>k;

    int ans = k/n;

    if(k%n!=0)
        ans++;

    cout<<ans;
    
    
    return 0;
}
