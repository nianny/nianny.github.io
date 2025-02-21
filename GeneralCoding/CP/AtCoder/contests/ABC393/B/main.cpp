#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
	string s;
	cin>>s;
	int count = 0;
	for (int i=0; i<s.length(); i++){
		if (s[i] == 'A'){
			for (int j=i+1; j<s.length(); j++){
				if (s[j] == 'B'){
					if (2*j-i < s.length() && s[2*j-i] == 'C') count ++;
				}
			}
		}
	}
	cout<<count;
}
