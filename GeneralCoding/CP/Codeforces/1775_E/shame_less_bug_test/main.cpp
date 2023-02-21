#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define DBGRUN(stmt) stmt
#define DBG1(x) cout << #x << ": " << (x) << endl
#define DBG2(x, y) cout << #x << ": " << (x) << ", " << #y << ": " << (y) << endl
#define DBG3(x, y, z) cout << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << endl
#define DBG4(w, x, y, z) cout << #w << ": " << (w) << ", " << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << endl
#define DBG_ARR(a, e) cout << #a << ": "; for (int i = 0; i < e; i++) cout << a[i] << ' '; cout << endl
#define DBG_ARR2D(a, s1, e1, s2, e2) cout << #a << ": " << endl; for (int i = s1; i < e1; i++) { for (int j = s2; j < e2; j++) cout << a[i][j] << ' '; cout << '\n'; }cout << endl
#define DBG_VEC(v) cout << #v << ": "; for (auto i : v) cout << i << ' '; cout << endl
#define DBG_HERE cout << "reached line: " << __LINE__ << endl
#else
#define DBGRUN(stmt)
#define DBG1(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG4(w, x, y, z)
#define DBG_ARR(a, e)
#define DBG_ARR2D(a, s1, e1, s2, e2)
#define DBG_VEC(v)
#define DBG_HERE
#endif
#define int long long
#define f first
#define s second
#define pii pair<int, int>
#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a)) 
#define FORN(a, b, c) for (int(a) = (b); (a) <= (c); ++(a))
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define ALLV(v) v.begin(), v.end() 
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz)) 
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
template <typename A, typename B> ostream& operator<<(ostream& out, const pair<A, B>& a) { out << "(" << a.first << ", " << a.second << ")"; return out; }
template<typename ...Ts, size_t ...Is> ostream& println_tuple_impl(ostream& os, tuple<Ts...> tuple, index_sequence<Is...>) { static_assert(sizeof...(Is) == sizeof...(Ts), "Indices must have same number of elements as tuple types!"); static_assert(sizeof...(Ts) > 0, "Cannot insert empty tuple into stream."); auto last = sizeof...(Ts) - 1; os << "("; return ((os << get<Is>(tuple) << (Is != last ? ", " : ")\n")), ...); }
template<typename ...Ts> ostream& operator<<(ostream& os, const tuple<Ts...>& tuple) { return println_tuple_impl(os, tuple, index_sequence_for<Ts...>{}); }
    
int N, R, G, Y;
int memo[401][401][401][3];
vector<int> rPos, gPos, yPos;
string S, A;
    
inline int dp(int RR, int GG, int YY, int lastUsed) {
    if (lastUsed != -1 && memo[RR][GG][YY][lastUsed] != -1)
        return memo[RR][GG][YY][lastUsed];
    if (RR == R && GG == G && YY == Y) return 0;
    int res = 1e18;
    // int idx = RR + GG + YY;
    
    if (RR < R && lastUsed != 0) {
        int nearestR = rPos[RR], ad = 0;
        // ad += max(GG - (upper_bound(gPos.begin(), gPos.end(), nearestR) - gPos.begin()), 0ll);
        // ad += max(YY - (upper_bound(yPos.begin(), yPos.end(), nearestR) - yPos.begin()), 0ll);
        int newRes = dp(RR + 1, GG, YY, 0) + ad;
        // DBG2(idx, lastUsed);
        // DBG3(ad, max(nearestR - idx, 0ll), newRes);
        res = min(res, newRes);
    }
    
    if (GG < G && lastUsed != 1) {
        int nearestG = gPos[GG], ad = 0;
        // ad += max(RR - (upper_bound(rPos.begin(), rPos.end(), nearestG) - rPos.begin()), 0ll);
        // ad += max(YY - (upper_bound(yPos.begin(), yPos.end(), nearestG) - yPos.begin()), 0ll);
        int newRes = dp(RR, GG + 1, YY, 1) + ad;
        res = min(res, newRes);
    }
    
    if (YY < Y && lastUsed != 2) {
        int nearestY = yPos[YY], ad = 0;
        // ad += max(RR - (upper_bound(rPos.begin(), rPos.end(), nearestY) - rPos.begin()), 0ll);
        // ad += max(GG - (upper_bound(gPos.begin(), gPos.end(), nearestY) - gPos.begin()), 0ll);
        int newRes = dp(RR, GG, YY + 1, 2) + ad;
        // DBG2(idx, lastUsed);
        // DBG3(ad, max(nearestY - idx, 0ll), newRes);
        res = min(res, newRes);
    }
    
    if (lastUsed != -1) memo[RR][GG][YY][lastUsed] = res;
    return res;
}
    
void dp2(int RR, int GG, int YY, int lastUsed) {
    if (RR == R && GG == G && YY == Y) return;
    int res = 1e18;
    char c;
    tuple<int, int, int, int> t = { -1, -1, -1, -1 };
    
    if (RR < R && lastUsed != 0) {
        if (memo[RR + 1][GG][YY][0] < res) {
            res = memo[RR + 1][GG][YY][0];
            t = { RR + 1, GG, YY, 0 };
            c = 'R';
        }
    }
    
    if (GG < G && lastUsed != 1) {
        if (memo[RR][GG + 1][YY][1] < res) {
            res = memo[RR][GG + 1][YY][1];
            t = { RR, GG + 1, YY, 1 };
            c = 'G';
        }
    }
    
    if (YY < Y && lastUsed != 2) {
        if (memo[RR][GG][YY + 1][2] < res) {
            res = memo[RR][GG][YY + 1][2];
            t = { RR, GG, YY + 1, 2 };
            c = 'Y';
        }
    }
    A += c;
    
    int a, b, cc, d;
    tie(a, b, cc, d) = t;
    DBG2(a + b + cc, res);
    dp2(a, b, cc, d);
}
    
int32_t main() {
    memset(memo, -1, sizeof memo);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> S;
    FOR(i, 0, N) {
        if (S[i] == 'R') {
            R++;
            rPos.push_back(i);
        }
        if (S[i] == 'G') {
            G++;
            gPos.push_back(i);
        }
        if (S[i] == 'Y') {
            Y++;
            yPos.push_back(i);
        }
    }
    int res = dp(0, 0, 0, -1);
    if (res >= 1e18) cout << -1;
    else {
        cout << res;
        // DBGRUN(dp2(0, 0, 0, -1));
        // DBG1(A);
    }
}