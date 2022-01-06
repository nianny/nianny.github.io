#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'

bool isTooMuch (int k, int d, int m) {
    int prev = k;
    int dist = prev;
    int increment = d + 1;
    // // k /= d;
    while (prev > 0) {
        prev = k/d;
        dist += prev;
        d *= increment;
        increment++;
    }

    return dist >= m;

    // int prevClimb = k;
    // int heightClimb = prevClimb;
    // int divisor = d;
    // int toTimes = divisor + 1;
    // while (prevClimb != 0){
    //     prevClimb = k / divisor;
    //     divisor *= toTimes;
    //     toTimes++;
    //     heightClimb += prevClimb;
    // }
    // return heightClimb >= m;
}


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int m, d;
    cin>>m>>d;

    int low = 0;
    int high = m;

    while (high - low > 1) {
        int mid = (low + high) / 2;

        if (isTooMuch(mid, d, m)) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout<<high<<endl;
    
    return 0;
}
