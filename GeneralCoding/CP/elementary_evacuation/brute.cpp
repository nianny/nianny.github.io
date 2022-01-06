#include <bits/stdc++.h>
#define int long long
using namespace std;
//typedef pair<int, int> pi;

int n, m, ans[1000005];

vector <int> v[1000005];

int dp(int x) {
	if (ans[x] != -1) {
		return ans[x];
	}
	if (v[x].size() == 0) {
		return 0;
	}
	for (int i = 0; i < v[x].size(); i++) {
		ans[x] = max(ans[x], dp(v[x][i]) + 1);
	}
	return ans[x];
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		cout << dp(i) << ' ';
	}
}