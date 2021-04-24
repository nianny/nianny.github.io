#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int maximum = 1000005;
int ft[1000005];
int arr[1000005];
int ls (int x){ //finds least sig bit
    return (x & (-x));
}
void update(int p, int v){
    for(; p <= n; p+= ls(p))ft[p] += v;
}
int query(int p){
    int sum = 0;
    for (; p; p -= ls(p)) sum = (sum + ft[p]);
    return sum;
}
int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    cin>>n;
    memset(ft, 0, sizeof ft);
    memset(arr, 0, sizeof arr);
    // update(0,1);
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        if (b > n){

        }
        else if (a == 1){
            if (!arr[b]){
                update(b,1);
            }
            arr[b] ++;

        }
        else {
            if (arr[b] == 1){
                update(b, -1);
            }
            if (!(arr[b] == 0)){
                arr[b] --;
            }
        }
        int l = 0, r = n+1, m = (r+l)/2;
        while(l+1<r){
            m = (r+l)/2;
            if (query(m) == m){
                l = m;
            }
            else {
                r = m;
            }
        }
        cout<<l<<'\n';

    }
    return 0;
}

/*
5 1 2 1 1 1 3 1 5 2 1
*/