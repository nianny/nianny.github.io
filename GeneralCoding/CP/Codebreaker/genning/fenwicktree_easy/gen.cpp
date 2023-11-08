#include "testlib.h"
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
// gen <min n> <max n> <min A[i]> <max A[i]> <min m> <max m> <min u> <max u> <seed> 
// u -> updates
int32_t main(int32_t argc, char* argv[])
{
    registerGen(argc, argv, 1);
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int minn = atoll(argv[1]);
    int maxn = atoll(argv[2]);
    int minA = atoll(argv[3]);
    int maxA = atoll(argv[4]);
    int minm = atoll(argv[5]);
    int maxm = atoll(argv[6]);
    int minu = atoll(argv[7]);
    int maxu = atoll(argv[8]);
    
    int n = rnd.next(minn, maxn);
    
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << rnd.wnext(minA, maxA) << ' ';
    }
    cout<<'\n';
    int m = rnd.next(minm, maxm);
    cout << m << '\n';

    int u = rnd.next(minu, maxu);
    for (int i=0; i<u; i++){
        cout<<1<<' ';
        cout<<rnd.next(1,n)<<' '<<rnd.next(minA,maxA)<<'\n';
    }
    for (int i=u; i<n; i++){
        cout<<0<<' ';
        int a = rnd.next(1,n);
        int b = rnd.next(a,n);
        cout<<a<<' '<<b<<'\n';
    }
}
 