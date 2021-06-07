#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<min(a,b)+min(c,d);
    return 0;
}