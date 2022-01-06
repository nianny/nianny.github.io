#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int n,m;
set<int> s;
vector<int> v;


// bool comp(int a, int b) {

// }
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    cin>>n>>m;

    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    for (int i=0; i<m; i++){
        int num;
        cin>>num;

        s.insert(num);
    }

    for (int i=0; i<n; i++){
        if (s.find(arr[i]) != s.end()){
            v.push_back(arr[i]);
        }
    }

    reverse(v.begin(), v.end());

    for (int i=0; i<v.size(); i++){
        cout<<v[i]<<' ';
    }
    return 0;
}


/*
7 5
1 2 3 4 5 16 7
3 2 8 5 16
*/