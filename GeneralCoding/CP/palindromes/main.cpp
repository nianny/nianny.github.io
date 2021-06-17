#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    string a;
    cin>>a;
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    string b = a;
    reverse(a.begin(), a.end());
    if (a == b){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}
