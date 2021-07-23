#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n;
    cin>>n;
    int man = 0;
    double eu = 0;
    int cheb = 0;
    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        a = abs(a);
        man += a;
        eu += a*a;
        cheb = max(cheb, a);
    }

    eu = sqrt(eu);
    cout.precision(18);
    cout<<man<<'\n'<<eu<<'\n'<<cheb;
    
    
    return 0;
}
