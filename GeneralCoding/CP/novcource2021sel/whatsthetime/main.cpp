#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n;

    cin>>n;
    int hours = (n/60)%24;
    string h = to_string(hours);
    int minutes = n%60;
    string m = to_string(minutes);

    if (h.length() == 1)
        h = "0" + h;
    if (m.length() == 1)
        m = "0" + m;

    cout<<h<<m;
    
    
    return 0;
}
