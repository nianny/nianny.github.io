#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    int n;
    cin>>n;

    int arr[n];

    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    // sort(arr, arr+n);



    cout<<arr[n/2];
    // else {
    //     cout<<(arr[n/2-1] + arr[n/2])/2;
    // }
    
    
    
    return 0;
}
