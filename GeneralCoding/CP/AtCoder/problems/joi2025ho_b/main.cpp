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

	int A[2*n+1];
	int B[2*n+1];
	int SS[2*n+1];
	int diff[2*n+1];
	memset(SS, 0, sizeof SS);
	memset(B, 0, sizeof B);
	memset(A, 0, sizeof A);
	memset(diff, 0, sizeof diff);

	for (int i=1; i<=n; i++){
		int a;
		cin>>a;
		A[i] = a;
		A[i+n] = a;
	}

	for (int i=1; i<=n; i++){
		int b;
		cin>>b;
		B[i] = b;
		B[i+n] = b;
	}

	
	for (int i=1; i<=2*n; i++){
		SS[i] = SS[i-1] + B[i];
	}

	for (int i=1; i<=2*n; i++){
		diff[i] = A[i] - SS[i-1];
	}

	
	deque< pair<int,int> >v;
	int ans = INT_MAX;
	int r = 1;
	for (int i=1; i<=n; i++){
		while(!v.empty() && v.front().first < i){
			v.pop_front();
		}
		while (v.empty() || r < i+n){
			while(!v.empty() && v.back().second <= diff[r]){
				v.pop_back();
			}

			v.push_back({r, diff[r]});
			r++;
		}

		ans = min(ans, v.front().second+SS[i-1]);

		// cout<<"hallo"<<'\t'<<i<<'\n';
		// for (int i=0; i<v.size(); i++){
		// 	cout<<v[i].first<<' '<<v[i].second<<'\n';
		// }
		// cout<<'\n';
	}
	cout<<ans;


}
