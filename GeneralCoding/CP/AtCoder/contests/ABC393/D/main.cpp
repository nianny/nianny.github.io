#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
	
	int n;
	cin>>n;
	char a[n];
	int zeroes = 0;
	for (int i=0; i<n; i++){
		cin>>a[i];
		if (a[i] == '0'){
			zeroes++;
		}
	}
	
	int zero_count = 0;
	int count = 0;
	for (int i=0; i<n; i++){
		if (a[i] == '0'){
			count += min(i-zero_count, n-zeroes+zero_count-i);
			zero_count++;
		}
	}
	cout<<count;
	
}
