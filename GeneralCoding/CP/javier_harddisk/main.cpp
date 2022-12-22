#include <bits/stdc++.h>
#define int long long int
#define pi pair<int, int> 
#define pb push_back
#define F first
#define S second
#define mp make_pair
using namespace std;


int N, C;
pi disks[50];
vector<pi> a, b;
vector<int> best, abin;

void bf1(int index, int size, int importance) {
	if (index == N / 2 + 1) {
		a.pb({ size, importance });
		return;
	}

	bf1(index + 1, size, importance);
	bf1(index + 1, size + disks[index].F, importance + disks[index].S);
}

void bf2(int index, int size, int importance) {
	if (index == N) {
		b.pb({ size, importance });
		return;
	}

	bf2(index + 1, size, importance);
	bf2(index + 1, size + disks[index].F, importance + disks[index].S);
}

int32_t main() {

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		int s, v; cin >> s >> v;
		disks[i] = { s, v };
	}

	bf1(0, 0, 0);
	bf2(N / 2 + 1, 0, 0);

	// for (auto el : a) {
	// 	cout << "(" << el.F << "," << el.S << ") ";
	// }
	// cout << endl;
	// for (auto el : b) {
	// 	cout << "(" << el.F << "," << el.S << ") ";
	// }

	sort(a.begin(), a.end());

	for (auto el : a) {
		abin.pb(el.F);
		best.pb(el.S);
	}

	for (int i = 1; i < N; i++) {
		best[i] = max(best[i - 1], best[i]);
		// a[i] = { a[i].F, max(a[i - 1].S, a[i].S) };
	}

	int ans = 0;

	for (auto el : b) {
		if (el.F > C) continue;
		int idx = upper_bound(abin.begin(), abin.end(), C - el.F) - abin.begin();
		ans = max(ans, el.S + best[idx - 1]);

		// S <= C
		// Sa + Sb <= C
		// Sa <= C - Sb
	}

	cout << ans << "\n";

	return 0;

}