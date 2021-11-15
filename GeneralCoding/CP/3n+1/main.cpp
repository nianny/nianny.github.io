#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n;
    cin>>n;
    cout<<n;

    while (n > 1){
        if (n % 2 == 0){
            n /= 2;
        }
        else {
            n = 3*n + 1;
        }
        cout<<' '<<n;
    }
    
    
    return 0;
}
