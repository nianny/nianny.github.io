#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    int h,w;
    cin>>h>>w;
    int line = w-h/2;
    for (int i=0; i<h/2+1; i++){
        for (int p=0; p<i; p++){
            cout<<' ';
        }
        for (int p=0; p<line; p++){
            cout<<'*';
        }
        for (int p=0; p<w-i-line; p++){
            cout<<' ';
        }
        cout<<'\n';
    }
    for (int i=h/2-1; i>=0; i--){
        for (int p=0; p<i; p++){
            cout<<' ';
        }
        for (int p=0; p<line; p++){
            cout<<'*';
        }
        for (int p=0; p<w-i-line; p++){
            cout<<' ';
        }
        cout<<'\n';
    }
    
    return 0;
}
