#include <bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<int, int>

using namespace std;

int m, n, s;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool visited[1010][1010];
int dist[1010][1010];

int bfs(vector<pi> sources) {
	queue<pi> q;

	memset(visited, false, sizeof(visited));
	memset(dist, -1, sizeof(dist));

	for (auto src : sources) {
		q.push({src.F, src.S});
		visited[src.F][src.S] = true;
		dist[src.F][src.S] = 1;		
	}
	int ans = 1;

	while (!q.empty()) {
		pi f = q.front();
		int curX = f.F;
		int curY = f.S;
		// cout << f.F << f.S << endl;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = curX + dx[i];
			int ny = curY + dy[i];
			if (nx < 0 or nx >= n) continue;
			if (ny < 0 or ny >= m) continue;
			if (visited[nx][ny]) continue;
			if (dist[nx][ny] != -1) dist[nx][ny] = min(dist[nx][ny], dist[curX][curY] + 1);
			else dist[nx][ny] = dist[curX][curY] + 1;
			ans = max(ans, dist[nx][ny]);
			q.push({nx, ny});
			visited[nx][ny] = true;
		}
	}
	return ans;
}

int32_t main() {
	cin >> m >> n >> s;
	vector<pi> seeds;
	for (int i = 0; i < s; i++) {
		int r, c;
		cin >> r >> c;
		seeds.pb({c - 1, r - 1});
	}

	cout << bfs(seeds) << endl;



	return 0;	
}
