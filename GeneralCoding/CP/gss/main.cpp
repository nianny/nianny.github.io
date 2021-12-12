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
    int sum = 0;

    for (int i=0; i<n; i++){
        cin>>arr[i];

        sum += arr[i];
    }
    

    sort(arr, arr+n, greater<int>());

    for (int i=3; i<n; i+=4){
        sum -= arr[i];
    }


    cout<<sum<<endl;
    
    return 0;
}
