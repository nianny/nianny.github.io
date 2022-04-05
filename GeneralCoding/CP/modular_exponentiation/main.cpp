#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n,m;
    cin>>m>>n;

    int ans = 1;
    while (ans <= n && m > 0){
        ans *= 2;
        m--;

        if (ans > n){
            cout<< n;
            return 0;
        }
        // cout<<ans;
    }

    cout<< n%ans<<endl;

    // cout<<n<<' '<<ans<<endl;
    
    return 0;
}
