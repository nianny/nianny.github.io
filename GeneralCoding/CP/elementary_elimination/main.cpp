#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    
    int n;
    cin>>n;

    stack<pair<int,int>> s;
    // s.push({(long long)0, (long long)0});
    int arr[n];

    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }

    reverse(arr, arr+n);
    // for (int i=1; i<=n; i++){
    //     int a;
    //     cin>>a;
    //     while(!s.empty() && s.top().first<a){
    //         s.pop();
    //     }
    //     cout<<s.top().second<<' ';
    //     s.push({a, i});
    // }
    
    vector<int>v;
    for(int i = 1; i <= n; ++i) {
		// int a; cin >> a;
		while(!s.empty() && s.top().first < arr[i-1]){
            s.pop();
        }
        if (s.empty()){
            // cout<<0<<' ';
            v.push_back(n+1);
        }
		else{
            v.push_back(s.top().second);
        }
		s.push({arr[i-1], i});
	}


    reverse(v.begin(), v.end());

    for (int i=0; i<n; i++) {
        cout<<n+1-v[i]<<' ';
    }
    return 0;
}


/*
5
1 5 3 2 4
*/
