#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;

    int ax,ay,bx,by,cx,cy;
    cin>>ax>>ay>>bx>>by>>cx>>cy;

    cout<<(((bx < ax && by < ay && cx < ax && cy < ay)||(bx < ax && by > ay && cx < ax && cy > ay) || (bx > ax && by < ay && cx > ax && cy < ay) || (bx > ax && by > ay && cx > ax && cy > ay))?"YES":"NO");
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

