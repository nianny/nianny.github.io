#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n;
    cin>>n;
    int count = 0;
    int arr[n+5];
    for (int i=1; i<=n; i++){
        cin>>arr[i];
        if (arr[i] == i){
            count++;
        }
    }

    int q;
    cin>>q;
    int ans = 0;

    for (int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;

        swap(arr[a], arr[b]);

        if (arr[a] == a){
            count++;
        }
        if (arr[b] == b){
            count++;
        }

        if (arr[a] == b){
            count--;
        }

        if (arr[b] == a){
            count--;
        }

        if (count == n){
            ans++;
        }

        
    }
    cout<<ans<<endl;
    for (int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    
    
    return 0;
}

/*
4 
3 4 1 2 

4
3 2
1 3
2 4
4 1
*/