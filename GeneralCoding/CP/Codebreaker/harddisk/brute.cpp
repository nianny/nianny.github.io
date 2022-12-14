#include <bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<int, int>

using namespace std;

int n, m, W[510], V[510], dp[510][510];


int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> W[i + 1] >> V[i + 1];
	}

	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= m; w++) {
			if (i == 0) {
				dp[i][w] = 0;
				continue;
			}
			dp[i][w] = max({dp[i][w - 1], dp[i - 1][w]});
			if (w - W[i] >= 0) {
				dp[i][w] = max({ dp[i][w], dp[i - 1][w - W[i]] + V[i] });
			}
		}
	}

	// for (int i = 0; i <= n; i++) {
	// 	cout << "(" << i << ") ";
	// 	for (int j = 0; j <= m; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << dp[n][m] << "\n";

	return 0;	
}