#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int maximum = 1000005;
int ft[1000005];
int ls (int x){ //finds least sig bit
    return (x & (-x));
}
void update(int l, int r, int v){
    r++; //update differences at r+1, not r
    for(; l <= maximum; l+= ls(l)) ft[l] = (ft[l] + v);
    for(; r <= maximum; r+= ls(r)) ft[r] = (ft[r] + v);
}
int query(int p){
    int sum = 0;
    for (; p; p -= ls(p)) sum = (sum + ft[p]);
    return sum;
}
int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    cin>>n;
    return 0;
}