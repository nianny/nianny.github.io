#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int h,w,n;
    cin>>h>>w>>n;

    int rows = n/w;
    for (int i=0; i<rows; i++){
        for (int p=0; p<w; p++){
            cout<<'X';
        }
        cout<<'\n';
    }
    int last = n%w;
    for (int i=0; i<last; i++){
        cout<<'X';
    }
    for (int i=0; i<w-last; i++){
        cout<<'O';
    }
    cout<<'\n';
    for (int i=0; i<h-rows-1; i++){
        for (int p=0; p<w; p++){
            cout<<'O';
        }
        cout<<'\n';
    }

    return 0;
}