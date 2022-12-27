#include "lampposts.h"
#include <bits/stdc++.h>
using namespace std;
#define int long long

static int L, N, A[100005], userans[100005], Q, userQ;

int nearest_lamppost(int X) {
	if (X < 0 || X > L) {
		printf("gug_reporting_string\nX out of range.\n");
		exit(0);
	}
	userQ++;
	if (userQ > Q) {
		printf("gug_reporting_string\nToo many queries made.\n");
		exit(0);
	} 
	int pos = lower_bound(A, A + N, X) - A;
	if (pos == N) return pos - 1;
	else if (pos == 0) return pos;
	else {
		if (abs(A[pos] - X) < abs(A[pos - 1] - X)) return pos;
		else return pos - 1;
	}
}

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

int32_t main() {
	scanf("%d%d%d", &L, &N, &Q);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	find_lampposts(L, N, userans);
	printf("gug_reporting_string\n");
	for (int i = 0; i < N; i++) printf("%d ", userans[i]);
	printf("\n");
	printf("%d queries made (out of %d).\n", userQ, Q);
}

