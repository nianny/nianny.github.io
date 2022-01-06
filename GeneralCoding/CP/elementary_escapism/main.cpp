#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int mod = 1000000007;

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    int n;
    cin>>n;
    int arr[n];
    multiset<int> s;

    for (int i=0; i<n; i++){
        cin>>arr[i];
        // cout<<arr[i]<<" ";
        s.insert(arr[i]);
    }
    int ans = 0;
    // cout<<"Hallooo";

    // while(!s.empty()){
    //     cout<<*s.begin()<<' ';
    //     s.erase(s.find(*s.begin()));
    // }
    // cout<<s.size()<<endl;
    while (s.size() > 0 && *--s.end() > 0) {
        // cout<<*--s.end()<<' ';

        // s.erase(s.find(*--s.end()));
        int size = s.size();
        int end = *--s.end();

        s.erase(end);

        int difference = end - *--s.end();


        ans += (((size-s.size())%mod) * end)%mod;

        for (int i=0; i<(size-s.size()); i++){
           s.insert(end-1);
        }
    }

    cout<<ans;
    
    
    return 0;
}
