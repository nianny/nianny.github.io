#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    int count = 0;
    int arr[13] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000};
    for (int i=12; i>=0; i--){
        if (n>=arr[i]){
            count += n/arr[i];
            n = n%arr[i];
        }
    }
    cout<<count;
    return 0;
}
