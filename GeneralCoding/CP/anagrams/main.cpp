#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    string s,t;
    cin>>s>>t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    if (s<t){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }


    return 0;
}