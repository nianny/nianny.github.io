#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    int n,m,x;
    cin>>n>>m>>x;

    int a,b,w;
    cin>>a>>b>>w;

    cout<<lcm(2*w,x)<<' ';

    int remainder = x- (w%x);
    if ((2*w)%x == 0){
        cout<<0<<' ';
    }
    else {
        cout<<lcm((2*w)%x, x-remainder)*(2*w)+w<<' ';
    }





    return 0;
}
