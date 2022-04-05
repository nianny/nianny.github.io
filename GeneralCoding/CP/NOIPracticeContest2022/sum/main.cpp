#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

inline int readInt() {
    int x   = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9') {
        x  = (x << 3) + (x << 1) + ch - '0';
        ch = getchar_unlocked();
    }
    return x;
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    

    int n = readInt();
    int x=0,y=0;
    for (int i=0; i<n; i++){
        int a,b;
        x+=readInt();
        y+=readInt();
    }

    cout<<x<<' '<<y;
    
    return 0;
}
