#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    int arr[n+5];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    int left[n+5];
    int right[n+5];

    int max_left = 0;
    int max_right = 0;

    for (int i=0; i<n; i++){
        left[i] = max_left;
        max_left = max(max_left, arr[i]);
    }

    for (int i=n-1; i>=0; i--){
        right[i] = max_right;
        max_right = max(max_right, arr[i]);
    }

    int sum = 0;
    for (int i =0; i<n; i++){
        sum += max((int) 0, (min(left[i], right[i]) - arr[i]));
    }
    cout<<sum;
    
    return 0;
}

// 7 5 6 1 3 2 9 8