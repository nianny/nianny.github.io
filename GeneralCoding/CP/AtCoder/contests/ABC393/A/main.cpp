#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;

	string a,b;
	cin>>a>>b;

	if (a=="sick"){
		if (b=="sick"){
			cout<<1;
		}
		else{
			cout<<2;
		}
	}
	else {
		if (b == "sick"){
			cout<<3;
		}
		else{
			cout<<4;
		}
	}

}
