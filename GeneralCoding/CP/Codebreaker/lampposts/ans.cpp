#include "lampposts.h"
#include <bits/stdc++.h>
using namespace std;
#define int long long

int arr[100005], values[100005];
int query(int X){
    if (arr[X] != -1) return arr[X];
    return arr[X] = nearest_lamppost(X);
}
void find_lampposts(int L, int N, int X[]){
    memset(arr, -1, sizeof arr);
    // values[0] = 0;
    X[0] = 0;
    for (int i=0; i<N-1; i++){
        int l = 0;
        int r = L;
        int mid;

        while (r-l > 0){
            mid = (l+r)/2;
            if (query(mid) <= i){
                l = mid;
            }
            else r = mid;
        }

        X[i+1] = (l*2-X[i]);
    }
}