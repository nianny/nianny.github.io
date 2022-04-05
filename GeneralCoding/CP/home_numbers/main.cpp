#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    int n,a;
    cin>>n>>a;

    if (a%2 == 1){
        cout<<(a/2)+1;
    }
    else{
        cout<<((n-a)/2+1);
    }
    
    
    return 0;
}
