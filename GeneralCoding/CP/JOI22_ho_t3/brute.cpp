#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi pair<int, int>
#define pii pair<int, pair<int, int> > 
#define fi first
#define se second
int n,k;
pair<long double, long double> A[300005];
bool cmp(pair<long double, long double> a, pair<long double, long double> b){
	return a.se < b.se;
}
long double dp[505][505];
void solve(){
	cin >> n >> k;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		cin >> A[i].fi >> A[i].se;
		if(A[i].se == -1)A[i].se = 1e18;
		else cnt++;
	}
	sort(A+1, A+n+1, cmp);
	long double ans = 1e18;
	for(int y=0;y<=min(k, cnt);y++){
		for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)dp[i][j] = 1e18;
		dp[0][0] = 0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				dp[i][j] = 1e18;
				if(j)dp[i][j] = min(dp[i][j], dp[i-1][j-1] + A[i].fi/(y+1));
				if(i-j <= y && j != i)dp[i][j] = min(dp[i][j], dp[i-1][j] + A[i].se/(i-j));
				else dp[i][j] = min(dp[i][j], dp[i-1][j]);
			}
		}
		ans = min(ans, dp[n][k-y]);
	}
	
	
	
	cout << fixed << setprecision(12) << ans;
}
 
main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
}