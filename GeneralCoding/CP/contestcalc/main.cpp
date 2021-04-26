#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    map<string,int>m;
    cin>>n;
    for (int i=0; i<n; i++){
        string a;
        int b;
        cin>>a>>b;
        m[a] = b;
    }

    int c;
    cin>>c;
    int sum = 0;
    for (int i=0; i<c; i++){
        string a;
        cin>>a;
        sum += m[a];
    }
    int average = sum/c;
    cout<<average;
    return 0;
}