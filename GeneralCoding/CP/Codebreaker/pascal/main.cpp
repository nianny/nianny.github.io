#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int r,c;
    cin>>r>>c;

    r--;
    c--;

    __int128 ans = 1;
    for (int i=r; i>r-c; i--) {
        ans *= i;
    }
    for (int i=1; i<=c; i++) {
        ans /= i;
    }

    cout<<(int)ans;
    
    return 0;
}
