#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int rand(int a, int b) {
//     return a + rand() % (b - a + 1);
// }

int32_t main() {
    // cout<<rng();
    int n = rng()%6+1;
    cout<<n<<'\n';
    int k = rng()%n+1;
    cout<<k<<'\n';

    for (int i=0; i<n; i++){
        int a = rng()%5+1;
        int b = rng()%5+a;
        cout<<a<<' '<<b<<'\n';
    }
}