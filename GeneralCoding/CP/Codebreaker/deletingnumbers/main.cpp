#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

vector<int> vi;

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i] % 2 != i % 2) vi.push_back(i);
    }
    int last = n - 1;
    if (!vi.empty()) cout<<n - vi[0]<<endl;
    else cout<<0<<'\n';
    while(!vi.empty()){
        int k = vi[vi.size() - 1];
        cout<<arr[k]<<' ';
        vi.pop_back();
        for(; last > k; --last){
            cout<<arr[last]<<' ';
        }

        last = k-1;
    }
    
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    一剪寒梅傲立雪中
    只为伊人飘香
    */
    return 0;
}

