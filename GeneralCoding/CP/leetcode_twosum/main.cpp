#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    cout<<lower_bound(arr, arr+10, 3)-arr;

    return 0;
}
