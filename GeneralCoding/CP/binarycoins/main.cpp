#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    hallo;
    unsigned long long b;
    cin>>b;
    int count = 0;
    while (b > 0){
        if (b & 1) count++;
        b >>= 1;
    }
    cout<<count;
    
    
    return 0;
}
