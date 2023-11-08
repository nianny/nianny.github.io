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


    int hours = (n/60)%24;
    int minutes = n%60;
    cout<<setfill('0')<<setw(2)<<hours;
    cout<<setfill('0')<<setw(2)<<minutes;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

