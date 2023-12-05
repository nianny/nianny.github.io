#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int a,b,c;
    cin>>a>>b>>c;
    if (min({a,b,c}) == 0) cout<<"FAIL";
    else{
        int sum = a+b+c;
        if (sum >= 85) cout<<"GOLD";
        else if (sum >=75) cout<<"SILVER";
        else if (sum >= 61) cout<<"PASS";
        else cout<<"FAIL";
    }
    /*
    Hallooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    */
    return 0;
}

