#include "minimum.h"
#include <bits/stdc++.h>
// using namespace std;

int findMin(int N, int A[]) {

    int ans = 2000000005;
    for (int i=0; i<N; i++){
        ans = min(ans, A[i]);
    }
    return ans+1;
}
