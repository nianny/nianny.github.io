#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);

map<char, int> m;
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
		char a;
		cin>>a;
		m[a] += 1;
	}
	
	for (auto it: m){
		cout<<it.first<<' '<<it.second<<'\n';
	}
	
	
    
    return 0;
}