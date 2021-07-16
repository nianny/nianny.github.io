#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi;
    int a,b;
    cin>>a>>b;
    for (int i=a; i<=b; i++){
        string x = to_string(i);
        string y = to_string(i);

        reverse(y.begin(), y.end());
        if (x==y){
            cout<<"Palindrome!";
        }
        else{
            cout<<i;
        }
        cout<<'\n';
    }

    
    return 0;
}
