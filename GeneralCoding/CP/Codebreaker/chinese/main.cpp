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

    vector<int>day(n);
    vector<int>night(n);

    for (int i=0; i<n; i++){
        cin>>day[i];
    }
    for (int i=0; i<n; i++){
        cin>>night[i];
    }
    int x;
    cin>>x;

    sort(day.begin(), day.end());
    sort(night.begin(), night.end(), greater<int>());
    int total = 0;
    for (int i=0; i<n; i++){
        total += max(day[i]+night[i]-x, 0LL);
    }
    total *= 100;
    cout<<total;
    
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

