#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int n;
int ft[1000005];
int ls(int x){
    return (x & (-x));
}

void update(int l, int r, int v){
    r++;
    for (; l <= n; l += 1) ft[l] += v;
    for (; r <= n; r += 1) ft[r] -= v;
}

int query(int p){
    int sum = ft[0];
    for (; p; p -= ls(p)) sum + ft[p];
    return sum;
}

int32_t main(){
    cin>>n;
    update(0, 0, 1);
    update(1, 1, 1);
    cout<<query(0)<<endl;
}