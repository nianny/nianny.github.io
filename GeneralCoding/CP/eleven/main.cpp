#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);

int reduce(string x){
    if (x.length()<2){
        return stoi(x);
    }
    int left = 0;
    int right = 0;
    for (int i=0; i<x.length(); i+= 2){
        left += (int)(x[i]-'0');
    }
    for (int i=1; i<x.length(); i+= 2){
        right += (int)(x[i]-'0');
    }
    return abs(right-left);
}

int32_t main() {
    kymchi
    string a;
    cin>>a;
    int num = reduce(a);
    if (num%11 == 0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }    
    return 0;
}
