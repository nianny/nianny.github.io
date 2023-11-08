#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int ft[1000005];
int arr[1000005];
int query(int p) {
    int sum = 0;
    for (; p; p -= p&-p) sum += ft[p];
    return sum;
}

void update(int p, int v) {
    for (; p<=1000000; p += p&-p) ft[p] += v;
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>arr[i];
        update(i,arr[i]);
    }

    int m;
    cin>>m;
    for (int i=0; i<m; i++){
        int t;
        cin>>t;

        if (t==1){
            int a,b;
            cin>>a>>b;
            update(a,b-arr[a]);
            arr[a] = b;
        }
        else {
            int a,b;
            cin>>a>>b;
            cout<<query(b)-query(a-1)<<'\n';
        }
    }
    return 0;
}
