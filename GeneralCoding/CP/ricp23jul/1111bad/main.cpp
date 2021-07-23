#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);

// int arr[100000005];
bool dp(int n){
    // if (arr[n] != -1) return arr[n];
    if (n==0) return true;
    int a = n;
    int p = 11;
    while (a>=p && p<=n){
        if (dp(a-p)) {
            // arr[n] = true;
            // return arr[n];
            return true;
        }
        p = p*10 + 1;
    }
    // arr[n] = false;
    // return arr[n];
    return false;
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int t;
    cin>>t;

    for (int i=0; i<t; i++){
        int num;
        cin>>num;
        if (dp(num)){
            cout<<"YES"<<'\n';
        }
        else {
            cout<<"NO"<<'\n';
        }
    }

    
    
    return 0;
}
