#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    int count = 0;
    for (int i=0; i<n; i++){
        string a;
        cin>>a;

        if (a == "chugga"){
            count++;
        }
    }

    if (count % 2== 0) cout<<"CHOO choo";
    else cout<<"choo CHOO";
    
    return 0;
}
