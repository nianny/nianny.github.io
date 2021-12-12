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

    for (int i=0; i<n; i++){
        int num, low, mid, high;
        cin>>num;

        low = 0;
        high = 1000000;

        while (high-low > 1) {
            mid = (low+high)/2;

            if (mid*mid*mid > num){
                high = mid;
            } else {
                low = mid;
            }

        }

        cout << low << endl;



    }
    
    
    return 0;
}
