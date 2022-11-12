#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int MAXTHINGI = 1e9+9;
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int sum = 1;
    for (int i=0; i<5; i++){
        int a;
        cin>>a;
        sum = (sum*(a%MAXTHINGI))%MAXTHINGI;
    }
    cout<<sum;
    
    return 0;
}
