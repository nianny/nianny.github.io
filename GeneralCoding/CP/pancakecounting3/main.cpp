#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXNUM 10000010
int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    bitset<MAXNUM>b;
    for (int i=0; i<n; i++){
        b<<=10;
        int a;
        cin>>a;
        int multipler = 1;
        for (int p=0; p<10; p++){
            multipler *= 2;
            if (a%multipler){
                b.set(p);
                a-=multipler/2;
            }
        }
    }
    int k; cin>>k;
    for (int i=0; i<n; i++){
        int num = (int)((b>>((n-1-i)*10)).to_ulong());
        cout<<num+k<<'\n';
        b = (b<<(MAXNUM-n*10+(i+1)*10))>>(MAXNUM-(n-1-i)*10);
    }
    return 0;
}
