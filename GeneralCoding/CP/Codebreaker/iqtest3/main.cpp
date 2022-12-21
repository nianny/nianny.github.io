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

    for (int i=0; i<n; i++){
        cout<<(2*i)%n+1<<' '<<(2*i+1)%n+1<<'\n';
    }
    return 0;
}
