#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    vector<int>v;
    v.push_back(5);
    v.push_back(1);
    v.push_back(10);
    sort(v.begin(), v.end());

    cout<<*lower_bound(v.begin(), v.end(), 1);
    cout<<'\n'<<*upper_bound(v.begin(), v.end(), 1);
    return 0;
}