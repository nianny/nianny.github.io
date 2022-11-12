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
    int maxsum[n+5];

    for (int i=1; i<=n; i++){
        char a;
        cin>>a;
        if (a == 'M'){
            arr[i] = -2;
        }
        else{
            arr[i] = a - '0';
        }
    }

    memset(maxsum, 0, sizeof maxsum);

    for (int i=1; i<= n; i++){
        maxsum[i] = max(maxsum[i-1], maxsum[i]) + arr[i];
    }
    
    cout<<*max_element(maxsum, maxsum+n+1);
    return 0;
}
