#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int t;
    cin>>t;

    for (int p=0; p<t; p++){
        int n,k;
        cin>>n>>k;
        int arr[k];
        for (int i =0; i<k; i++){
            int x;
            cin>>x;
            arr[i] = n-x;
        }

        sort(arr, arr+k);
        
        int count = 0;
        int sum = 0;
        while (count < k && sum + arr[count]<= n && arr[count]<=(n-count)){
            sum += arr[count];
            count++;
        }

        cout<<count<<'\n';
    }
    
    return 0;
}
