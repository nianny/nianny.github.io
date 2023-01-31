#include <bits/stdc++.h>
using namespace std;
#define FOR(i,s,e) for(int i = s; i <= (int)e; ++i)
#define DEC(i,s,e) for(int i = s; i >= (int)e; --i)
#define IAMSPEED ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
#define db(x) cerr << #x << "=" << x << "\n"
#define db2(x, y) cerr << #x << "=" << x << " , " << #y << "=" << y << "\n"
#define db3(a,b,c) cerr<<#a<<"="<<a<<","<<#b<<"="<<b<<","<<#c<<"="<<c<<"\n"
#define dbv(v) cerr << #v << ":"; for (auto ite : v) cerr << ite << ' '; cerr <<"\n"
#define dbvp(v) cerr << #v << ":"; for (auto ite : v) cerr << "{"  << ite.f << ',' << ite.s << "} "; cerr << "\n"
#define dba(a,ss,ee) cerr << #a << ":"; FOR(ite,ss,ee) cerr << a[ite] << ' '; cerr << "\n"
#define reach cerr << "LINE: " << __LINE__ << "\n";
#else
#define reach 
#define db(x)
#define db2(x,y)
#define db3(a,b,c)
#define dbv(v)
#define dbvp(v)
#define dba(a,ss,ee)
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define f first 
#define s second
#define g0(x) get<0>(x)
#define g1(x) get<1>(x)
#define g2(x) get<2>(x)
#define g3(x) get<3>(x)
typedef pair <int, int> pi;
typedef tuple<int,int,int> ti3;
typedef tuple<int,int,int,int> ti4;
int rand(int a, int b) { return a + rng() % (b-a+1); }
const int MOD = 1e9 + 7;
const int inf = (int)1e9 + 500;
const long long oo = (long long)1e18 + 500;
template <typename T> bool chmax(T& a, const T b) { return a<b ? a = b, 1 : 0; }
template <typename T> bool chmin(T& a, const T b) { return a>b ? a = b, 1 : 0; }
const int MAXN = 402;
int dp[MAXN][MAXN][MAXN][3];
int C[3][MAXN][MAXN][MAXN];//number of positions i have moved forward
int A[MAXN];
vector<int>V[3];
int where[3][MAXN];
int32_t main() 
{
	IAMSPEED
	int n; cin >> n;
	FOR(i,1,n) {
		char c; cin >> c;
		if(c=='R')A[i]=0;
		else if(c=='G')A[i]=1;
		else A[i]=2;
		V[A[i]].pb(i);
	}
	FOR(zz,0,2) {
		FOR(i,1,V[zz].size()) {
 
			int pos=V[zz][i-1];
			set<int> s;
			for(auto x:{0,1,2})s.insert(x);
			s.erase(zz);
			int c1=*s.begin(); s.erase(s.begin());
			int c2=*s.begin(); s.erase(s.begin());
			int cnt=0;
			FOR(xx,0,V[c1].size()) {
				int id1=0;
				if(xx)id1=V[c1][xx-1];
				if(id1>pos)++cnt;
				int st=cnt;
				FOR(yy,0,V[c2].size()) {
					int id2=0;
					if(yy)id2=V[c2][yy-1];
					if(id2>pos)++cnt;
					C[zz][i][xx][yy]=cnt;
				}
				cnt=st;
			}
		}
	}
 
	FOR(i,0,n)FOR(j,0,n)FOR(k,0,n)FOR(y,0,2)dp[i][j][k][y]=inf;
	dp[0][0][0][0]=0;
	dp[0][0][0][1]=0;
	dp[0][0][0][2]=0;
	FOR(i,0,V[0].size()) {
		FOR(j,0,V[1].size()){
			FOR(k,0,V[2].size()) {
				FOR(y,0,2) {
					int &cur=dp[i][j][k][y];
					if(cur==inf)continue;
					if(y!=0){ 
						if(i<V[0].size()){
							int curidx=C[0][i+1][j][k];
 
							chmin(dp[i+1][j][k][0], cur + curidx);
						}
					}
					if(y!=1) {
						if(j<V[1].size()) {
							int curidx=C[1][j+1][i][k];
							chmin(dp[i][j+1][k][1], cur + curidx);
						}
					} 
					if(y!=2){
						if(k<V[2].size()) {
							int curidx=C[2][k+1][i][j];
							chmin(dp[i][j][k+1][2], cur + curidx);
						}
					}
				}
			}
		}
	}
	int r=V[0].size();
	int g=V[1].size();
	int b=V[2].size();
	int ans = min({dp[r][g][b][0], dp[r][g][b][1], dp[r][g][b][2]});
	if(ans==inf)cout<<-1;
	else cout <<ans;
}