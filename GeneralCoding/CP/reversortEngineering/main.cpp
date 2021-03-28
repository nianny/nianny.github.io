#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int n,c;
        cin>>n>>c;
        if (n-1>c or n*2-2 < c){
            cout<<"Case #"<<i+1<<": IMPOSSIBLE\n";
            continue;
        }

        //possible cases
        int diff = c - n+1;
        int pos = n-1 - diff;
        cout<<"Case #"<<i+1<<": ";
        for (int p=0; p<pos; p++){
            cout<<p+1<<' ';
        }
        cout<<n<<' ';
        for (int p=pos; p<n-1; p++){
            cout<<p+1<<' ';
        }
        cout<<'\n';
        // cout<<pos;
    }
    return 0;
}