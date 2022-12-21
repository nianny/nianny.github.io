#include<bits/stdc++.h>
using namespace std;
#define int long long

// pragmas


// getchar fast io
inline int readInt() {
	int x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar_unlocked();
	while (ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar_unlocked();
	}
	return x;
}
/* segment tree
struct node {
	int n;
	int l;
	int r;
	int m;
	int prop;
	node *lnode=nullptr, *rnode=nullptr;
	
	node(int x, int y) {
		n = 0;
		l = x;
		r = y;
		m = (x+y)/2;
		prop = 0;
		
		
		// normal creation
		if (l != r){
			lnode = new node(l, m);
			rnode = new node(m+1, r);
		}
		
	}
	
	
	// lazy node
	void create (){
		if (l != r){
			lnode = new node(l,m);
			rnode = new node(m+1,r);
		}
	}
	
		
	// lazy prop function
	void lazyprop() {
		if (lnode == nullptr){create();}
		if (prop != 0){
			n += prop*(r-l+1);
			if (l != r){
				lnode->prop += prop;
				rnode->prop += prop;
			}
			prop = 0;
		}
	}
	
	
	// point update max
	void pupdate (int nupd, int kupd){
		if (l == r){
			n = kupd;
		}
		else {
			if (nupd <= m){
				lnode -> pupdate(nupd, kupd);
			}
			else if (nupd > m){
				rnode -> pupdate(nupd, kupd);
			}
			n = max((lnode->n),(rnode->n));
		}
	}
	
	
	// range update sum
	void rupdate (int lupd, int rupd, int kupd){
		// only for lazy node
		if (lnode == nullptr){create();}
		
		// only for lazy prop
		lazyprop();
		
		if (lupd == l && rupd ==r){
			prop += kupd;
		}
		else if (rupd <= m){
			lnode->rupdate(lupd, rupd, kupd);
		}
		else if (lupd > m){
			rnode->rupdate(lupd, rupd, kupd);
		}
		else  {
			lnode->rupdate(lupd, m, kupd);
			rnode->rupdate(m+1, rupd, kupd);
		}
		
		if (l != r){
			lnode->lazyprop();
			rnode->lazyprop();
			n = lnode->n + rnode->n;
		}
		
	}
	
	// query max
	int query(int lbound, int rbound){
		// only for lazy node
		if (lnode == nullptr){create();}
		
		// only for lazy prop
		lazyprop();
		
		if (lbound==l && rbound==r){
			return n;
		}
		else if (rbound <= m){
			return lnode -> query(lbound,rbound);
		}
		else if (lbound > m){
			return rnode -> query(lbound,rbound);
		}
		else  {
			return max((lnode->query(lbound,m)),(rnode->query(m+1,rbound)));
		}
	}
};*/
/* adjlist weighted
vector<pair<int,int>> adjlist[n+1];
for (int i=0; i<e; i++){
	a = readInt();
	b = readInt();
	z = readInt();
	adjlist[a].push_back(make_pair(b,z));
	adjlist[b].push_back(make_pair(a,z));
	}*/
/* Dijkstra
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> simo;
	for (int i=0; i<=n; i++){dist[i] = -1;}
	simo.push(make_pair(0,1));
	dist[1] = 0;
	while (simo.size() > 0){
		pair<int,int> c = simo.top();
		simo.pop();
		if (abs(c.first - dist[c.second]) > 0) {continue;}
		for (int j=0; j<adjlist[c.second].size(); j++){
			pair<int,int> i;
			i = make_pair(adjlist[c.second][j].first, adjlist[c.second][j].second);
			if (dist[i.first] == -1 || dist[i.first] > c.first + i.second){
				dist[i.first] = c.first + i.second;
				simo.push(make_pair(dist[i.first], i.first));
			}
		}
	}*/
/* tree to line
int st[1000000];
int end[1000000];
int cnt;
void dfs(int x){
	cnt++;
	st[x] = cnt;
	for (int i=0; i<adjlist[x].size(); i++){
		dfs(adjlist[x][i]);
	}
	end[x] = cnt-1;
}*/
/* depth first search with distance
void dfs(int x) {
	if (visited[x] == 1) return;
	visited[x] = 1;
	dist[x] = dis;
	dis++;
	for (int i=0; i<adjl[x].size(); i++) {
		dfs(adjl[x][i]);
	}
}
*/
/* breadth first search with distance
queue<int> simo;
visited[1] = 1;
dist[1] = 0;
simo.push(1);
while (simo.size() > 0){
	int v = simo.front();
	simo.pop();
	for (int i=0; i<adjlist[v].size(); i++){
		if (visited[adjlist[v][i]] == 1){
			continue;
		}
		simo.push(adjlist[v][i]);
		visited[adjlist[v][i]] = 1;
		dist[adjlist[v][i]] = dist[v] + 1;
	}
}
*/

// variables
int n;
int e;
int a;
int b;
int z;
int dist1[50000];
int dist2[50000];
int prevx;
int k;
int x;
int y;
int ans;

// main
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	n = readInt();
	e = readInt();
	vector<pair<int,int>> adjlist[n];
	for (int i=0; i<e; i++){
		a = readInt();
		b = readInt();
		z = readInt();
		adjlist[a].push_back(make_pair(b,z));
		adjlist[b].push_back(make_pair(a,z));
	}
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> simo1;
	for (int i=0; i<=n; i++){dist1[i] = -1;}
	simo1.push(make_pair(0,0));
	dist1[0] = 0;
	while (simo1.size() > 0){
		pair<int,int> c = simo1.top();
		simo1.pop();
		if (abs(c.first - dist1[c.second]) > 0) {continue;}
		for (int j=0; j<adjlist[c.second].size(); j++){
			pair<int,int> i;
			i = make_pair(adjlist[c.second][j].first, adjlist[c.second][j].second);
			if (dist1[i.first] == -1 || dist1[i.first] > c.first + i.second){
				dist1[i.first] = c.first + i.second;
				simo1.push(make_pair(dist1[i.first], i.first));
			}
		}
	}
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> simo2;
	for (int i=0; i<=n; i++){dist2[i] = -1;}
	simo2.push(make_pair(0,n-1));
	dist2[n-1] = 0;
	while (simo2.size() > 0){
		pair<int,int> c = simo2.top();
		simo2.pop();
		if (abs(c.first - dist2[c.second]) > 0) {continue;}
		for (int j=0; j<adjlist[c.second].size(); j++){
			pair<int,int> i;
			i = make_pair(adjlist[c.second][j].first, adjlist[c.second][j].second);
			if (dist2[i.first] == -1 || dist2[i.first] > c.first + i.second){
				dist2[i.first] = c.first + i.second;
				simo2.push(make_pair(dist2[i.first], i.first));
			}
		}
	}
	
	prevx = dist1[n-1];
	k = readInt();
	for (int i=0; i<k; i++){
		x = readInt();
		y = readInt();
		ans = max(prevx - dist1[x] - dist2[y], prevx - dist2[x] - dist1[y]) - 1;
		if (ans <= 0){cout << "-1" << "\n";}
		else {cout << ans << "\n";}
	}
}