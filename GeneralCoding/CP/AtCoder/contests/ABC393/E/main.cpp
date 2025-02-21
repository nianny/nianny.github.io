#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
	int n,k;
	cin>>n>>k;

	vector<int> A(n);
	for (int i=0; i<n; i++){
		cin>>A[i];
	}

	int M = *max_element(A.begin(), A.end());

	vector<int> S(M+1), T(M+1), U(M+1);

	for (int i=0; i<n; i++){
		S[A[i]]++; // S[x] is how many times x appears in A
	}


	for (int i=1; i<=M; i++){
		for (int d=i; d<=M; d+=i){
			T[i] += S[d]; // T[x] is how many times multiples (e.g. 2x, 5x) of x appear in A
		}
	}
	// cout<<"Hallo!";

	for (int i=1; i<=M; i++){
		if (T[i] < k) continue;
		for (int j=i; j<=M; j+=i){
			U[j] = i;
		}
	}

	for (int i=0; i<n; i++){
		cout<<U[A[i]]<<'\n';
	}



	// for (int i=1; i<=M; i++){
	// 	cout<<S[i]<<' ';
	// }
	// cout<<'\n';

	// for (int i=1; i<=M; i++){
	// 	cout<<T[i]<<' ';
	// }
	// cout<<'\n';

	// for (int i=1; i<=M; i++){
	// 	cout<<U[i]<<' ';
	// }
	// cout<<'\n';
}
