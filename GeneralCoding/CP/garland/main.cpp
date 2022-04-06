#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n;
int arr[105];
int odd,even;

int dp(int pos, bool parity){
    if (arr[pos] != 0) return min(dp(pos-1, parity), dp(pos-1, !parity)+1);
    else if (parity) return dp(pos-1, parity);
    else return dp(pos-1, !parity)+1;
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    cin>>n;
    set<int> s;
    for (int i=1; i<=n; i++){
        s.insert(i);
    }
    
    for (int i=0 ; i<n ; i++) {
        cin>>arr[i];
        s.erase(arr[i]);
    }

    for (auto it: s){
        if (it%2==0) even++;
        else odd++;
    }

    cout<<min(dp(n-1, true), dp(n-1, false))<<endl;




    
    return 0;
}
