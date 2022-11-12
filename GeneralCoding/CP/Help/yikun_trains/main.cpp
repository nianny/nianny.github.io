#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N; cin >> N;
    ll pts[N+2];
    pts[0] = 1000000000;
    pts[N+2] = 0;

    for (ll i = 1; i < N+1; i++) {
        cin >> pts[i];
    }

    ll mem[N];
    mem[0] = 0;
    for (ll i = 1; i <= N + 3; i++) {
        ll j = 1;
        while (pts[i] > pts[i-j]) {
            j++;
        }
        mem[i] = pow(j, 2) + mem[i-j];
    }

    cout << mem[N];
}

