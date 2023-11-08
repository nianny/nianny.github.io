#include <bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define mp make_pair

using namespace std;

int N, W, w[100010], v[110];

int memo[110][100010];

int dp(int index, int weight) {
	int& ans = memo[index][weight];
	if (ans != -1) return ans;

	if (index < 0 or weight < 0) return ans = 0;

	// do not take item
	ans = dp(index - 1, weight);

	// take the item
	if (weight >= w[index]) {
		ans = max(ans, dp(index - 1, weight - w[index]) + v[index]);
	}

	return ans;
}


int32_t main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	memset(memo, -1, sizeof(memo));

	cin >> N >> W;	
	for (int i = 0; i < N; i++) {
		cin >> w[i] >> v[i];
	}

	cout << dp(N, W) << "\n";

	return 0;	
}