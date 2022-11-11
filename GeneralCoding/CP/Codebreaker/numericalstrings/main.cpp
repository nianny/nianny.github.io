#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


bool cmp(string a, string b){
    if (a.size() == b.size()){
        return a+b > b+a;
    }
    return a.size() > b.size();
}

bool cmp2(string a, string b){
    return a+b > b+a;
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,k;
    cin>>n>>k;
    string arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n, cmp); 
    vector<string>v;
    for (int i=0; i<k; i++){
        v.push_back(arr[i]);
    }
    sort(v.begin(), v.end(), cmp2);
    string final = "";
    for (int i=0; i<k; i++){
        final += v[i];
    }

    cout<<final<<'\n';
    return 0;
}
