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

    vector<int> arr (n+5);
    for (int i=0; i<n; i++){
        cin>>arr[i]; 
    }
    
    vector<int> v;
    
    for (int i=0; i<n; i++){
        if ((v.empty()) || v.back() < A[i]) v.push_back(A[i]);
        else{
            *(lower_bound(v.begin(), v.end(), A[i])) = A[i];
        }
    }

    cout<<v.size();
    return 0;
}
