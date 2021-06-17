#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    int maxi = 0;
    int index = 0;
    int num = 1;
    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        if (a > maxi){
            maxi = a;
            index = i+1;
            num = 1;
        }
        else if (a == maxi){
            num++;
        }
    }
    if (num > 1){
        cout<<"MMMMMEEEEOOOOOWWWW!!!!!";
    }
    else {
        cout<<index;
    }
    
    return 0;
}
