#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n,k;
    cin>>n>>k;
    int arr[n];
    priority_queue<int> negative;
    priority_queue<int, vector<int>, greater<int>> positive;
    vector<int> pos;
    int sum = 0;
    for (int i=0; i<n; i++){
      cin>>arr[i];
      if (arr[i] < 0){
        negative.push(arr[i]);
      }
      else if (arr[i] > 0){
        positive.push(arr[i]);
      }
      if (abs(arr[i]) <= k){
        pos.push_back(abs(arr[i]));
      }
      sum += arr[i];
    }
    pos.push_back(k);
    sort(pos.begin(), pos.end());

    int ans = sum;
    int previous = 0;
    for (auto it: pos){
      // cout<<sum<<'\t'<<negative.size()<<'\t'<<positive.size()<<'\n';
      int difference = 0;
      difference += negative.size();
      difference -= positive.size();

      difference *= (it-previous);
      previous = it;

      while (!negative.empty() && (negative.top() + it) >= 0){
        negative.pop();
      }
      while(!positive.empty() && (positive.top() - it) <= 0){
        positive.pop();
      }

      // cout<<it<<'\t'<<difference<<'\t'<<sum<<'\n';
      sum += difference;
      ans = max(ans, sum);

    }

    cout<<ans;


    // cout<<ans;

    return 0;
}


/*

7 6
1 -3  -2 4 -5 8 0
*/
