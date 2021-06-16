#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    string num;
    cin>>num;
    reverse(num.begin(), num.end());
    int multipler = 1;
    int sum = 0;
    for (int i=0; i<num.length(); i++){
        if (num[i] == '1'){
            sum += multipler;
        }
        multipler *= 2;
    }
    cout<<sum;
    return 0;
}
