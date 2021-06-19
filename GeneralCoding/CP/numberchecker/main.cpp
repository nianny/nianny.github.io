#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int32_t main() {
    kymchi
    string a;
    cin>>a;
    if (isNumber(a)){
        cout<<stoi(a)*2;
    }
    else{
        transform(a.begin(), a.end(), a.begin(), ::toupper);
        cout<<a;
    }
    
    return 0;
}
