#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int rand(int a, int b) {
//     return a + rand() % (b - a + 1);
// }

int32_t main() {
    int n = rng()%10+1;
    cout<<n<<'\n';
    for (int i=0; i<n; i++){
        int a,b;
        if (i==0){
            a = -1;
        }
        else{
            a = rng()%n;
        }

        b = rng()%10;
        cout<<a<<' '<<b<<'\n';
    }
}