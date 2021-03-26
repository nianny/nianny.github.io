#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int t;
    cin>>t;

    for (int p=0; p<t; p++){
        int n,k;
        cin>>n>>k;

        char string[n+5];
        for (int i=1; i<=n; i++){
            cin>>string[i];
        }
        int ans = 0;

        for (int i=1; i<= n/2; i++){
            if (string[i] != string[n-i+1]){
                ans++;
                //cout<<string[i]<<' '<<string[n-i+1]<<'\n';
            }
            //cout<<' ';
            //cout<<' ';
        }
        cout<<"Case #"<<p+1<<": "<<abs(ans-k)<<'\n';
    }


    return 0;
}