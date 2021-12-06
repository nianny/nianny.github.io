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
    int arr[n+5];
    memset(arr,0,sizeof(arr));
    for (int i=2; i<=n; i++){
        int x;
        cin>>x;
        arr[x]++;
    }

    for (int i=1; i<=n; i++){
        cout<<arr[i]<<endl;
    }
    
    
    return 0;
}
