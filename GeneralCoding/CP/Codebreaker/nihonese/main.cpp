#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifttream cin("addin.txt");
    // ofttream cout("addout.txt");
    kymchi;
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;

    bool flag1 = true;
    bool flag2 = true;
    for (int i=0; i<n-1; i++){
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'||s[i] =='n'){
            continue;
        }

        if (!(s[i+1] == 'a' || s[i+1] == 'e' || s[i+1] == 'i' || s[i+1] == 'o' || s[i+1] == 'u')){
            flag1 = false;
            break;
        }
    }

    if (!(s[n-1] == 'a' || s[n-1] == 'e' || s[n-1] == 'i' || s[n-1] == 'o' || s[n-1] == 'u'|| s[n-1] == 'n')) flag1 = false;

    for (int i=0; i<m-1; i++){
        if (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u' ||t[i] =='n'){
            continue;
        }

        if (!(t[i+1] == 'a' || t[i+1] == 'e' || t[i+1] == 'i' || t[i+1] == 'o' || t[i+1] == 'u')){
            flag2 = false;
        }
    }
    if (!(t[m-1] == 'a' || t[m-1] == 'e' || t[m-1] == 'i' || t[m-1] == 'o' || t[m-1] == 'u' || t[m-1] == 'n')) flag2 = false;

    if (flag1 && flag2){
        cout<<"su"<<endl;
    }
    else if (flag1 || flag2){
        cout<<"wan"<<endl;
    }
    else{
        cout<<"zero"<<endl;
    }
    
    
    return 0;
}