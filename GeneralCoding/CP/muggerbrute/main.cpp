#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    int a[n];
    int b[n];

    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    for (int i=0; i<n; i++){
        cin>>b[i];
    }
    int arr[n+5];
    memset(arr, 0, sizeof arr);
    for (int i=0; i<n; i++){
        arr[i] = a[i];
        for (int p=0; p<i; p++){
            arr[i] = max(arr[i], (arr[p]+a[i]-((b[i]-b[p])*(b[i]-b[p]))));
        }
    }
    int maximum = 0;
    for (int i=0; i<n; i++){
        maximum = max(maximum, arr[i]);
    }
    cout<<maximum;
    // cout<<arr[n-1];
    return 0;
}