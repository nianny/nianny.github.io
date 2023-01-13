#include <bits/stdc++.h>

#define int long long int
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<int, int>

using namespace std;

int N, M, D[200010];

struct node {
	int s, e, m;
	int val = 0; int pos = 0;
	node *l, *r;
	node (int _s, int _e) {
		s = _s; e = _e; m = (s + e) / 2;
		if (s != e) {
			l = new node(s, m);
			r = new node(m + 1, e);
			if (l -> val >= r -> val) {
				val = l -> val;
				pos = l -> pos;
			}
			else {
				val = r -> val;
				pos = r -> pos;
			}
		}
		else {
			val = D[s];
			pos = s;
		}
	}
	pi query(int _s, int _e) {
		// cout << "(" << _s << "." << _e << " own: " << s << "." << e << " pos: " << pos << ")\n";
		if (_s == s and _e == e) {
			return { val, pos };
		}
		else {
			if (_s > m) return r -> query(_s, _e);
			else if (_e <= m) return l -> query(_s, _e);
			else {
				pi left = l -> query(_s, m);
				pi right = r -> query(m + 1, _e);
				if (left.F >= right.F) {
					return left;
				}
				else {
					return right;
				}
			}
		}
	}

	void del(int sus) {
		if (s == e) {
			val = -1;
			// return;
		}
		else {
			if (pos > m) r -> del(sus);
			else l -> del(sus);

			if (l -> val >= r -> val) {
				val = l -> val;
				pos = l -> pos;
			}
			else {
				val = r -> val;
				pos = r -> pos;
			}
			// cout << s << e << endl;
			// cout << "(" << s << ", " << e << ") V: " << val << " Pos: " << pos << endl;
		}
	}
} *root;

int32_t main() {


	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> D[i];
	}
	root = new node(0, N - 1);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		// cout << root -> query(0, 1).F << "&" << root -> query(0, 1).S << endl;
		// for (int i = 0; i < N; i++) {
		// 	int test = root -> query(i, i).F;
		// 	cout << (test == LLONG_MIN / 2 ? -1 : test) << " ";
		// }
		// cout << endl;
        for (int x=0; x<N; x++){
            cout<<root->query(x,x).first<<' '<<root->query(x,x).second<<'\n';
        }
        cout<<"2 4: "<<root->query(2,4).first<<' '<<root->query(2,4).second<<'\n';
        cout<<"3 4: "<<root->query(3,4).first<<' '<<root->query(3,4).second<<'\n';
        cout<<'\n';
		pi qry = root -> query(a, b);
        cout<<a<<' '<<b<<' '<<qry.first<<'\t'<<qry.second<<'\n';
        root -> del(qry.S);
        cout << qry.F << "\n";
	}


	return 0;	
}