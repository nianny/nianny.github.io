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
    int sa, sb, sc, sd;
    int n;
    cin >> sa >> sb >> sc >> sd >> n;
    
    sa = a;
    sb = b;
    sc = c;
    sd = d;
    
    for (int num20 = 0; num20 <= b; num20++){
        a = sa;
        b = sb;
        c = sc;
        d = sd;
        int num = n;
        cout<<num<<' ';
        num -= num20 * 20;
        if (num < 0){
            continue;
        }
        while(d > 0 && num >= 50){
            num -= 50;
            d--;
        }
        while(b > 0 && num >= 10){
            num -= 10;
            b--;
        }
        while(a > 0 && num >= 5){
            num -= 5;
            a--;
        }

        if (num == 0){
            cout<< sa-a << " " << sb-b << " " << sc-c << " " << sd-d << ' ' << sa+sb+sc+sd-a-b-c-d;
            return 0;
        }
        cout<<num20<<' '<<num<<'\n';
    }
    cout<< -1; 
    return 0;
}
