#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int t;
    cin>>t;

    for (int tc = 0; tc<t; tc++){
        int ax,ay,bx,by;
        cin>>ax>>ay>>bx>>by;

        cout<<abs(ax-bx)+abs(ay-by)+((ax==bx || ay==by)?0:2)<<endl;
    }
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

