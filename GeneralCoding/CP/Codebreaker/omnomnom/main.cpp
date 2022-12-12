#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int>adjlist[100010];
int par[100010];
//0 means no taking current
//1 means taking current

void root(int x, int p){
	par[x] = p;
	for (auto i: adjlist[x]){
		if (i == p) continue;
		root(i,x);
	}
}
int memo[100010][2];
int dp(int x, int pol){
	if (memo[x][pol] != -1) return memo[x][pol];
	int ans = 0;
	if (pol ==0){
		for (auto i: adjlist[x]){
			if (par[i] != x) continue;
			ans += max(dp(i,0), dp(i,1));
		}
	}
	else{
		for (auto i: adjlist[x]){
			if (par[i] !=x) continue;
			ans += dp(i,0);
		}
		ans++;
	}
	return memo[x][pol] = ans;
}
		
int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	
	for (int i=0; i<n-1; i++){
		int a,b;
		cin>>a>>b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	
	//*
	root(1,-1);
	memset(memo, -1, sizeof memo);
	cout<<max(dp(1,0), dp(1,1));
	//*/
	
}
