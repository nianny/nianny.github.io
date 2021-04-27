#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    int mini[n];
    int maxi[n];
    for (int i=0; i<n; i++){
        cin>>mini[i];
    }
    for (int i=0; i<n; i++){
        cin>>maxi[i];
    }
    int minimum = 0;
    int maximum = 1001;
    for (int i=0; i<n; i++){
        minimum = max(minimum, mini[i]);
        maximum = min(maximum, maxi[i]);
    }

    if (maximum < minimum){
        cout<<0;
    }
    else{
        cout<<maximum-minimum+1;
    }
    return 0;
}