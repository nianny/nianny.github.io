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
    int a[n];
    int b[n];

    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    
    for (int i=0; i<n; i++){
        cin>>b[i];
    }

    sort (a, a+n);
    sort (b, b+n, greater<int>());


    int sum = 0;

    for (int i=0; i<n; i++) {
        sum += a[i]*b[i];
    }

    cout<<sum<<endl;
    
    return 0;
}
