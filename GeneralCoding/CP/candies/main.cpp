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
        if (a == 1){
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
        for (int p=1; p<=n; p++){
            // cout<<p<<' '<<query(p)<<' '<<arr[p]<<' '<<'\n';
            if (query(p) != p){
                cout<<p-1<<'\n';
                break;
            }
            
        }
    }
    return 0;
}

/*
5 1 2 1 1 1 3 1 5 2 1
*/