#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

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

int X[10000000], Y[10000000];

int32_t main(){
    hallo;
	int N = readInt();
	for(int i = 0; i < N; i++) {
		X[i] = readInt();
		Y[i] = readInt();
		// write code here
	}

    stack<pair<int,int>> s;

    for (int i=0; i<N; i++){
        
        while (!s.empty() && abs(X[i]-s.top().first) <= Y[i]-s.top().second){
            s.pop();
        }
        if (s.empty() || abs(s.top().first-X[i]) > s.top().second-Y[i]) s.push({X[i], Y[i]});
    }

    cout<<s.size();
	// write code here
	return 0;
}

