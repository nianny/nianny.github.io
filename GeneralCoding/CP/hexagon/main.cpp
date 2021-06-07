#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;

    for (int i=n-1; i>=0; i--){
        for (int p=0; p<i; p++){
            cout<<' ';
        }
        for (int p=0; p<2*(n-1-i)+n; p++){
            cout<<'x';
        }
        // for (int p=0; p<i; p++){
        //     cout<<' ';
        // }
        cout<<'\n';
    }
    for (int i=1; i<n; i++){
        for (int p=0; p<i; p++){
            cout<<' ';
        }
        for (int p=0; p<2*(n-1-i)+n; p++){
            cout<<'x';
        }
        cout<<'\n';
    }
    return 0;
}

/*
xxxxxxxxxxxxxxx
xxxxxxxxxxxxxxx
*/