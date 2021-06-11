#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int h,w;
    cin>>h>>w;
    int peanut = 0;
    int potato = 0;
    for (int i=0; i<h; i++){
        for (int p=0; p<h; p++){
            char a;
            cin>>a;
            if (a == 'O'){
                potato++;
            }
            else if (a == 'N'){
                peanut ++;
            }
        }
    }
    cout<<potato<<' '<<peanut;
    return 0;
}
