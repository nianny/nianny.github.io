#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n,s;
    cin>>n>>s;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n, greater<int>());
    int sum = 0;
    for (int i=0; i<min(s,n); i++){
        sum += arr[i];
    }
    for (int i=s; i<n; i++){
        sum += arr[i] *2;
    }
    cout<<sum;
    return 0;
}