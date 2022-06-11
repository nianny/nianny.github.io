#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    deque<int> arr;
    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    int ans = 0;
    arr.pop_back();
    while(!arr.empty()){
        arr[0]--;
        ans++;
        if (arr[0] == 0){
            arr.pop_front();
        }
        if (arr.empty()){
            break;
        }
        arr.pop_back();
    }
    cout<<ans;


    
    return 0;
}
