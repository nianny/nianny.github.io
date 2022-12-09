#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
bool cmp(string a, string b){
    if (a.length() == b.length()) return a < b;
    else{
        return a.length() < b.length();
    }
    // return a < b;
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    string arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n, cmp);

    for (int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
    
    
    return 0;
}
