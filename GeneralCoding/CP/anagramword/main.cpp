#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi
    string a,b;
    getline(cin,a);
    getline(cin,b);
    multiset<char>sa;
    multiset<char>sb;
    for (int i=0; i<a.length(); i++){
        if (isalpha(a[i])){
            sa.insert((char)tolower(a[i]));
        }
    }
    for (int i=0; i<b.length(); i++){
        if (isalpha(b[i])){
            sb.insert((char)tolower(b[i]));
        }
    }
    if (sa == sb){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    
    return 0;
}
