#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n,k;
    cin>>n;
    vector<short int> arr;
    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        arr.push_back((short int)a);
    }
    cin>>k;
    for (int i=0; i<n; i++){
        cout<<((int)arr[i] + k)<<'\n';
    }
    
    return 0;
}
