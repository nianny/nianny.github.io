#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


long long N,K;
int A[500005];
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    cin>>N>>K;

    for (int i=1; i<=N; i++) cin>>A[i];
    for (int i=2; i<=N; i++) A[i] += A[i-1];

    long long ans = 1000000000007ll, ind = -1;
    for (int i=K; i<=N; i++) {
        if (ans > A[i] - A[i-K]) {
            ans = A[i] - A[i-K];
            ind = i-K+1;
        }
    }

    cout<<ind;
    return 0;
    
    
    return 0;
}
