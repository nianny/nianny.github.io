#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,k;
    cin>>n>>k;
    int W[n];
    int P[n];
    for (int i=0; i<n; i++){
        cin>>W[i];
    }
    int sum = 0;
    for (int i=0; i<n; i++){
        cin>>P[i];

        if ((P[i]*W[i])<k){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}

