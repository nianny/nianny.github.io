#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long
typedef pair<int,int> pi;
#define f first
#define s second
 
const int maxn = 100010;
 
int n;
int A[maxn], D[maxn];
int dp[maxn];
int ans = 0;
 

//Convex hull
deque <pi> dq;
 
int f(pi line, int x) { //return y after we sub in x to the line
    return line.f * x + line.s;
}
 
int query(int x) {
    while (!dq.empty() and f(dq[0],x) < f(dq[1],x)) { //as long as its is not an empty convex hull, and while the value y of the first is lower than the second, pop front
        dq.pop_front();
    }
    return f(dq[0], x); //return the value of the first one (highest)
}
 
long double intersect(pi a, pi b) {
    return ((long double)b.s - a.s) / ((long double)a.f - b.f);
}
 
void insert(int m, int c) {
    int s = dq.size() - 1;  
    pi line = pi(m,c); 
    while (dq.size() >= 2 and intersect(dq[s], line) < intersect(dq[s-1],line)) {
        dq.pop_back();
        s = dq.size() - 1;
    }
    dq.push_back(line);
}
 
 
int32_t main() {
    FAST
    cin >> n;
    for (int i =0;i<n;i++) cin >> A[i];
    for (int i =0;i<n;i++) cin >> D[i];
    
    //We are currently at book i
    //The best score at dp[i] = max(dp[j] + A[i] - (D[i] - D[j])^2) for all j
    
    for (int i =0;i<n;i++) {
        dp[i] = A[i]; //take book i as first book
        
        if (!dq.empty()) dp[i] = max(dp[i], query(D[i]) + A[i] - D[i]*D[i]);
        
        insert(2*D[i], dp[i] - D[i]*D[i]);
 
        //~ cout << i << " " << dp[i] << "\n";
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
}