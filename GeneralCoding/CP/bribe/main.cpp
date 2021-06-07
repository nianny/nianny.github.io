#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    // ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    int prices[n];
    for (int i=0; i<n; i++){
        scanf("%lld", &prices[i]);
    }
    int e;
    cin>>e;
    int friends[n];
    memset(friends, 0, sizeof friends);
    for (int i=0; i<e; i++){
        int a,b;
        scanf("%lld", &a);
        scanf("%lld", &b);
        friends[a-1]++;
        friends[b-1]++;
    }
    double best = 0;
    int index = 0;
    for (int i=0; i<n; i++){
        if ((double)friends[i]/prices[i] > best){
            best = (double)friends[i]/prices[i];
            index = i;
        }
    }

    printf("%lld", index+1);
    return 0;
}