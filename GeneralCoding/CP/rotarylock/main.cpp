#include <bits/stdc++.h>
using namespace std;
#define int long long
int modulo=1;
int n,q,k;
int ft[1000005];
int ls (int x){ //finds least sig bit
    return (x & (-x));
}
void update(int l, int r, int v){
    r++; //update differences at r+1, not r
    for(; l <= n; l+= ls(l)) ft[l] = (ft[l] + v)% modulo;
    for(; r <= n; r+= ls(r)) ft[r] = (ft[r] + v) % modulo;
}
int query(int p){
    int sum = 0;
    for (; p; p -= ls(p)) sum = (sum + ft[p]) % modulo;
    return sum;
}
int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    
    cin>>n>>q>>k;
    for (int i=0; i<k; i++){
        modulo *= 2;
    }
    // for (int i=1; i<=n; i++){
    //     int a;
    //     cin>>a;
    //     update(i,i,a);
    // }
    memset(ft,0,sizeof ft);
    for (int i=0; i<q; i++){
        int a,b,c;
        cin>>a;
        if (a==0){
            cin>>b>>c;
            // cout<<a<<' '<<b<<' '<<c<<' '<<'\n';
            update(b,n,c);
        }
        else {
            cin>>b;
            // cout<<"HALLO";
            cout<<query(b) % modulo<<'\n';
        }
    }
    return 0;
}
/*
4 6 100000
0 3 2
1 2
1 4
0 2 1
1 2
1 3
*/