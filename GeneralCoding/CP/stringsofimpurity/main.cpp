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

    int count = 0;
    int pos = 0;
    int current = 0;

    while (current < t.size()) {
        if (t[current] == s[pos]) {
            current++;
        }
        pos++;

        if (pos == s.size()) {
            pos = 0;
            count++;
        }
    }

    cout<<count*s.size() + pos<<endl;
    
    
    return 0;
}
