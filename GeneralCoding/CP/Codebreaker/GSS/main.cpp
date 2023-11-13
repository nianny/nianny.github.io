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

    int sum = 0;
    vector<int>v(n);
    for (int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i=0; i<n; i++){
        if (i%4 != 3){
            sum += v[i];
        }
    }
    cout<<sum;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

