#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    int n;
    cin>>n;
    int m = 0;
    int f=0;
    for (int i=0; i<n; i++){
        string a;
        cin>>a;
        if (a=="MEW"){
            m++;
        }
        else if (a=="MEOW"){
            f++;
        }
    }
    if (m==0){
        cout<<"OMG MEEEAHHHH!!!!";
    }
    else{
        cout<<f/m;
    }
    
    return 0;
}
