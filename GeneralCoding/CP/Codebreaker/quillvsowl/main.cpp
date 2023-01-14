#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
inline void read(int& x) {
    x = 0;
    char ch = getchar_unlocked();
    while (ch < '0' || ch > '9') ch = getchar_unlocked();
    while (ch >= '0' && ch <= '9' ) {
        x = (x << 3) + (x << 1) + (ch & 15);
        ch = getchar_unlocked();
    }
}

// int main(){
// 	read(N); read(M); read(K); read(H); read(L);
// 	for (int i = 0; i < N; i++) {
// 		read(P[i]);
// 	}
	
	
// }

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,m,k,h,l;
    read(n); read(m); read(k); read(h); read(l);
    int H[n+5];
    int Q[m+5];
    for (int i=1; i<=n; i++){
        read(H[i]);
    }
    for (int i=1; i<=m; i++){
        read(Q[i]);
    }
    bool arr[n+5];
    memset(arr, false, sizeof arr);

    for (int i=0; i<h; i++){
        int a;
        read(a);

        arr[a] = true;
    }

    int sum = 0;
    int counter = 1;
    deque<int>dq;

    int ans = 0;
    for (int i=1; i<=n; i++){
        while (counter <= m && (Q[counter]-H[i]) <= k){
            dq.push_back(counter);
            sum ++;
            counter++;
        }

        while(!dq.empty() && (H[i]-Q[dq.front()]) > k){
            dq.pop_front();
            sum--;
        }

        if (arr[i]){
            if (sum > l) ans++;
        }
        else{
            if (sum) ans++;
        }
    }
    cout<<ans;

    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

