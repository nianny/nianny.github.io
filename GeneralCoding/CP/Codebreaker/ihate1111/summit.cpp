#include <bits/stdc++.h>

using namespace std;
int m, d;

long long maxheight(long long int k) {
    long long int x = 1, denomenator;
    long long int sumheight = 0;

    for (int i = 0; k/x > 0; i++) { //integer value, purposely truncated
        if (i == 0) {
            x = 1;
            sumheight += k/x;
        } else if (i == 1) {
            x = d;
            sumheight += k/x;
        } else if (i > 1) {
            denomenator = d;
            for (int j = 1; j < i; j++) {
				denomenator *= (d + j);
            }
            x = denomenator;
            sumheight += k/x;
        }
    }

    return sumheight;
}

int main() {
    
    cin >> m >> d;
    long long int high = m, low = 0;
	long long int mid;
    while (high - low > 1) {
        mid = (high + low)/2;
        if (maxheight(mid) >= m) {
            high = mid;
        } else {
            low = mid;
        }
    }
    
    cout << high;

    return 0;
}

