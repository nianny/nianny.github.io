#define DBG_VEC(v)                                                                                 \
    cout << #v << ": ";                                                                            \
    for (auto i : v)                                                                               \
        cout << i << ' ';                                                                          \
    cout << endl
#define DBG_HERE cout << "reached line: " << __LINE__ << endl
#else
#define DBG(x)
#define DBG2(x, y)
#define DBG3(x, y, z)
#define DBG_ARR(a, s, e)
#define DBG_ARR2D(a, s1, e1, s2, e2)
#define DBG_VEC(v)
#define DBG_HERE
#endif
#define int long long
template <typename A, typename B> ostream &operator<<(ostream &out, const pair<A, B> &a) {
    out << "(" << a.first << ", " << a.second << ")";
    return out;
}

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int n, k;
int A[100010];

int32_t main() {
    FAST;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int lidx = 0;
    int ridx = n - 1;

    for (int i = 0; i < k; i++) {
        if (lidx >= ridx || lidx >= n - 1 || ridx <= 1) {
            cout << 0;
            return 0;
        }

        int ldiff = A[lidx + 1] - A[lidx];
        int rdiff = A[ridx] - A[ridx - 1];
        // DBG2(ldiff, rdiff);
        if (ldiff < rdiff) {
            // DBG_HERE;
            A[ridx] = A[ridx - 1];
            ridx--;
        } else {
            // DBG_HERE;
            A[lidx] = A[lidx + 1];
            lidx++; 
        }

        // DBG_ARR(A, 0, n);
    }

    int ans = 0;
    for (int i = lidx; i <= ridx - 1; i++) {
        ans += A[i + 1] - A[i];
    }
    cout << ans;

    return 0;
}