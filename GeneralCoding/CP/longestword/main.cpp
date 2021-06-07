#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    string best = "";
    for (int i=0; i<n; i++){
        string a;
        cin>>a;
        if (a.length() > best.length()){
            best = a;
        }
    }
    cout<<best;

    return 0;
}