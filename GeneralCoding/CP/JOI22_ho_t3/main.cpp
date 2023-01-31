#include <bits/stdc++.h>
using namespace std;
#define int long long
#define intd long double
#define debug(x) cout << '|' << x << '|' << '\n';
#define debug2(x, y) cout << x << " | " << y << '\n';
#define debug3(x, y, z) cout << x << " | " << y << " | " << z << '\n';

deque<pair<int, int>> v;
intd memo[510][510];
vector<int> precomp;
int N, K, intendedA;

intd dp(int idx, int sizeOfA) {
    if (memo[idx][sizeOfA] != 0) return memo[idx][sizeOfA];
    if (idx == N) return (sizeOfA == intendedA ? 0 : __LONG_LONG_MAX__);
    intd res = __LONG_LONG_MAX__;
    int sizeOfB = K - intendedA + 1;

    // take B
    if (idx < v.size() && v[idx].first != -1) {
        if (idx - sizeOfA + 1 >= sizeOfB) {
            res = min(res, dp(idx + 1, sizeOfA));
            // cout << idx << " " << sizeOfA << " " << "DON'T TAKE ANYTHING: " << dp(idx + 1, sizeOfA) << endl;
        }
        else {
            res = min(res, dp(idx + 1, sizeOfA) + (intd)v[idx].first / (intd)(idx - sizeOfA + 1));
            // cout << idx << " " << sizeOfA << " " << "TAKE B: " << dp(idx + 1, sizeOfA) + (intd)v[idx].first / (intd)(idx - sizeOfA + 1) << endl;
        }
    }
    // take A
    if (idx < v.size() && sizeOfA < intendedA) {
        res = min(res, dp(idx + 1, sizeOfA + 1) + (intd)v[idx].second / (intd)sizeOfB);
        // cout << idx << " " << sizeOfA << " " << "TAKE A: " << dp(idx + 1, sizeOfA + 1) + (intd)v[idx].second / (intd)sizeOfB << endl;
    }
    // take remainder of A
    if (sizeOfA != intendedA && intendedA - sizeOfA - 1 < precomp.size() && (idx - sizeOfA) >= sizeOfB - 1) {
        res = min(res, (intd)precomp[intendedA - sizeOfA - 1] / (intd)sizeOfB);
        // cout << idx << " " << sizeOfA << " TAKE REMAINDER OF A: " << (intd)precomp[intendedA - sizeOfA - 1] / (intd)sizeOfB << endl;
    }

    memo[idx][sizeOfA] = res;
    return res;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if ((a.first == -1 && b.first == -1) || (a.first != -1 && b.first != -1)) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
    if (b.first == -1) return true;
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        v.push_back(make_pair(B, A));
    }
    sort(v.begin(), v.end(), cmp);
    // for (auto i : v) cout << i.first << " " << i.second << endl;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (v[i].first == -1) {
            if (cnt == 0) precomp.push_back(v[i].second);
            else precomp.push_back(precomp.back() + v[i].second);
            cnt++;
            v.pop_back();
        }
    }
    // for (auto i : precomp) cout << i << endl;
    cout << fixed << setprecision(12);

    intd res = __LONG_LONG_MAX__;
    for (int i = 0; i <= K; i++) {
        intendedA = i;
        memset(memo, 0, sizeof memo);
        // cout << intendedA << endl;
        res = min(res, dp(0, 0));
    }
    cout << res;
}
