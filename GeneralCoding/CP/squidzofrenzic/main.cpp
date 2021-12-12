#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'



int n,m;
int arr[100010];

bool ispossible (int a) {
    int count = 0;
    int current = 0;

    for (int i=0; i<n; i++){
        if (arr[i] + current > a) {
            count++;
            current = arr[i];
        }
        else {
            current += arr[i];
        }
    }

    if (current > 0) count++;

    if (count <= m) return true;
    else return false;
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    cin>>n>>m;
    int max_num = 0;

    for (int i=0; i<n; i++) {
        cin>>arr[i];
        max_num += arr[i];
    }

    int low = 0;
    int high = max_num;

    while (high - low > 1) {
        int mid = (low + high) / 2;
        if (ispossible(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout<<high<<endl;
    
    
    return 0;
}
