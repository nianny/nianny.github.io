#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int rand(int a, int b) {
//     return a + rand() % (b - a + 1);
// }

int32_t main() {
    int n = rng()%10+2;
    cout<<n<<'\n';
    for (int i=2; i<=n; i++){
        cout<<i<<' ';
        cout<<rng()%(i-1)+1<<'\n';
    }
    // cout<<rng();
}