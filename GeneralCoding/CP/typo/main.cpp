#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    string s,t;
    cin>>s>>t;

    string c = s;

    for (int i=0; i<s.size()-1; i++){
        if (c==t) {
            cout<<"Yes"<<endl;
            return 0;
        }
        
        swap(c[i],c[i+1]);
        if (c==t) {
            cout<<"Yes"<<endl;
            return 0;
        }
        swap(c[i],c[i+1]);
    }
    cout<<"No"<<endl;   
    
    
    return 0;
}
