// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
// #define endl '\n'


// int32_t main() {
//     // ifstream cin("addin.txt");
//     // ofstream cout("addout.txt");
//     kymchi;
//     int n,k;
//     cin>>n>>k;

//     int a[n];

//     for (int i=0; i<n; i++) {
//         cin>>a[i];
//     }

//     int suffix[n];
//     suffix[n-1] = a[n-1];

//     for (int i=n-2; i>=0; i--) {
//         suffix[i] = a[i]+suffix[i+1];
//     }
//     int ans = suffix[0];
//     sort(suffix+1, suffix+n, greater<int>());

//     // for (int i=0; i<n; i++){
//         // cout<<suffix[i]<<" ";
//     // }


//     for (int i=1; i<k; i++) {
//         ans += suffix[i];
//     }
//     // ans += suffix[0];

//     cout<<ans<<endl;
    
    
//     return 0;
// }
/*
5 2
-1 -2 5 -4 8
*/


#include <bits/stdc++.h>
using namespace std;

#define int long long
#define DBG(x) cout << #x << ": " << x << '\n'
#define DBG2(x, y) cout << #x << ": " << x << ", " << #y << ": " << y << '\n'
#define DBG3(x, y, z)                                                                              \
    cout << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << '\n'
#define DBG_ARR(x)                                                                                 \
    cout << #x << ": ";                                                                            \
    for (int i = 0; i < n; i++)                                                                    \
        cout << x[i] << " ";                                                                       \
    cout << '\n'
#define FAST                                                                                       \
    ios_base::sync_with_stdio(0);                                                                  \
    cin.tie(0);                                                                                    \
    cout.tie(0)
template <typename A, typename B> ostream &operator<<(ostream &out, const pair<A, B> &a) {
    out << "(" << a.first << ", " << a.second << ")";
    return out;
}

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, k;
int ans;
int A[300010], suffixsum[300010];

int32_t main() {
    FAST;

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = n - 1; i >= 0; i--)
        suffixsum[i] = suffixsum[i + 1] + A[i];
    ans += suffixsum[0];
    // DBG_ARR(suffixsum);
    sort(suffixsum + 1, suffixsum + n, greater<int>());
    // DBG_ARR(suffixsum);
    for (int i = 1; i < k; i++)
        ans += suffixsum[i];
    cout << ans;

    return 0;
}

