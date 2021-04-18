#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q;
int ft[200005];
int ls (int x){ //finds least sig bit
    return (x & (-x));
}
void update(int l, int r, int v){
    r++; //update differences at r+1, not r
    for(; l <= n; l+= ls(l)) ft[l] += v;
    for(; r <= n; r+= ls(r)) ft[r] -= v;
}
int query(int p){
    int sum = 0;
    for (; p; p -= ls(p)) sum += ft[p];
    return sum;
}
int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    cin>>n>>q;
    for (int i=1; i<=n; i++){
        int a;
        cin>>a;
        update(i,i,a);
    }
    for (int i=0; i<q; i++){
        int a,b,c,d;
        cin>>a;
        if (a==1){
            cin>>b>>c>>d;
            update(b,c,d);
        }
        else {
            cin>>b;
            cout<<query(b)<<'\n';
        }
    }
    return 0;
}