#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int moneyTypes[13] = {1000000, 500000, 100000, 50000, 10000, 5000, 1000, 500, 100, 50, 10, 5, 1};
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    
    long long N;
    cin >> N;
    int total = 0;
    sort(moneyTypes, moneyTypes + 13, greater<int>());
    for (int type : moneyTypes) {
        total += N / type;
        N -= (N / type) * type;
    }
    cout << total << endl;
    return 0;
}
