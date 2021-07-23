#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    string a;
    cin>>a;
    a = "0"+a;
    string b = a;
    reverse(a.begin(), a.end());
    if (a==b){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<'\n';
    }
    
    
    return 0;
}
