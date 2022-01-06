#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'
int n,m;

int arr[3000005];

bool check (int k) {
    int count = 0;

    for (int i=0; i<m; i++){
        if (arr[i]%k == 0) count+= arr[i]/k;
        else count+= arr[i]/k + 1;
    }

    if (count <= n) return true;
    else return false;
}


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    
    cin>>n>>m;

    for (int i=0; i<m; i++){
        cin>>arr[i];
    }

    int low = 0;
    int high = 10e15;

    while (high - low > 1) {
        int mid = (low + high) / 2;

        if (check(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout<<high<<endl;
    
    
    return 0;
}
