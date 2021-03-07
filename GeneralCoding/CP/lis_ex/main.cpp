#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    int a[n];
    
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    

    vector<int> value;
    for (int i==0; i<n; i++){
        if (value.empty() or value.back() < a[i]){
            value.push_back(a[i]);
        }
        else {
            *(lower_bound(value.begin(), value.end(), a[i])) = a[i];
        }
    }
    return 0;
}