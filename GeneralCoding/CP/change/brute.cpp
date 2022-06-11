#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int a,b,c,d;
    int num;
    cin >> a >> b >> c >> d >> num;
    int sa, sb, sc, sd;
    sa = a;
    sb = b;
    sc = c;
    sd = d;
    while(d > 0 && num >= 50){
        num -= 50;
        d--;
    }
    while(c > 0 && num >= 20){
        num -= 20;
        c--;
    }
    while(b > 0 && num >= 10){
        num -= 10;
        b--;
    }
    while(a > 0 && num >= 5){
        num -= 5;
        a--;
    }

    if (num > 0){
        cout<< -1;
    }
    else{
        cout<< sa-a << " " << sb-b << " " << sc-c << " " << sd-d << ' ' << sa+sb+sc+sd-a-b-c-d;
    }

    
    
    
    return 0;
}
