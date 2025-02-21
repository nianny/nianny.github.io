#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
	int n,m;
	cin>>n>>m;

	int count = 0;
	set<int>adjlist[n+5];
	for (int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		if (a == b || adjlist[a].find(b) != adjlist[a].end()){
			count++;
		}
		else {
			adjlist[a].insert(b);
			adjlist[b].insert(a);
		}
	}
	cout<<count;
}
