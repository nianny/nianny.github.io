#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

bool comp(int a, int b){
    return a&1 < b&1;
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    int arr[n+5];
    for (int i=0; i< n; i++){
        arr[i] = i+1;
    }

    sort (arr, arr+n, comp);
    
    
    return 0;
}
