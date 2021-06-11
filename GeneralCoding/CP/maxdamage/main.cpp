#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    char choice;
    cin>>choice;
    int p, s;
    cin>>p>>s;
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    double multiplier;
    int attack = a+b+c+d;
    if (choice == 'G'){
        multiplier = 1.6;
    }
    else if (choice == 'K'){
        multiplier = 1.7;
    }

    cout<<fixed<<setprecision(2);
    double ans = multiplier * ((4*p)+s) * ((double)attack/100);
    cout<<ans;
    return 0;
}
