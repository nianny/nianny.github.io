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
    for (int i=1; i<=n; i++){
        cin>>arr[i];
    }

    int front[n+5];
    int back[n+5];
    memset(front, 0, sizeof front);
    memset(back, 0, sizeof back);
    for (int i=1; i<=n; i++){
        front[i] = max(arr[i], front[i-1] + arr[i]);
    }
    for (int i=n; i>=1; i--){
        back[i] = max(arr[i], back[i+1] + arr[i]);
    }
    int ans = 0;

    int frontm[n+5];
    int backm[n+5];
    memset(frontm, 0, sizeof frontm);
    memset(backm, 0, sizeof backm);
    for (int i=1; i<=n; i++){
        frontm[i] = max(front[i], frontm[i-1]);
    }
    for (int i=n; i>=1; i--){
        backm[i] = max(back[i], backm[i+1]);
    }
    for(int i=1; i<=n; i++){
        ans = max(ans, frontm[i] + backm[i+1]);
    } 
    cout<<ans;
    
    return 0;
}
