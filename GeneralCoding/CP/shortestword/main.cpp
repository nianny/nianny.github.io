#include <bits/stdc++.h>
using namespace std;
#define int long long

bool comparator(string a, string b){
    return a.length() < b.length();
}

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    string arr[n];
    for (int i=0; i<n; i++){
       cin>>arr[i]; 
    }

    sort(arr, arr+n, comparator);
    cout<<arr[0];
    return 0;
}
