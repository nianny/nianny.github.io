#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define debug(x) cout << #x << " is " << x << '\n';
#define debug2(x, y) cout << #x << " is " << x << ", " << #y << " is " << y << '\n';
#define debug3(x, y, z) cout << #x << " is " << x << ", " << #y << " is " << y << ", " << #z << " is " << z << '\n';

pair<int, int> A[300000];
pair<int, int> original[300000];
int C[300000];

int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, K;
  cin >> N >> K;
  for(int i = 0; i < N; i++){
    int Z;
    cin >> Z;
    A[i] = make_pair(Z, i);
  }
  for(int i = N-1; i >= 0; i--)
    A[i] = make_pair(A[i].first + A[i + 1].first, A[i].second);
  
  for (int i=0; i<N; i++){
  	cout<<A[i].first<<" ";
  }
  int ans = A[0].first;
  copy(A, A + N, original);
  sort(A+1, A + N, greater<pair<int, int>>());
  for (int i=0; i<N; i++){
  	cout<<A[i].first<<" ";
  }
  for (int i = 1; i < K; i++)
  {
    pair<int, int> cur = A[i];
    ans += original[cur.second].first;
  }
  cout << ans;
}