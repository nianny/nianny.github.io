#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi;
    int n,s;
    cin>>n>>s;
    bool flag = false;
    vector<int> arr;
    int count = 0;
    int add = 0;
    int keep = n;
    for (int i=0; i<keep; i++){
        int x;
        cin>>x;
        if (x==0 && !flag){
            n--;
        }
        else if (x == 1 && !flag){
            // cout<<n<<' '<<i<<'\n';
            flag = true;
        }

        if (flag){
            if (x == 0){
                add++;
                // cout<<i<<'\n';
            }
            else {
                arr.push_back(add);
                count ++;
                add = 0;
            }
        }
    }
    // cout<<add<<' ';
    n-=add;
    // cout<<n<<'\n';

    sort(arr.begin(), arr.end(), greater<int>());
    // cout<<n<<'\n';
    // for (auto it: arr){
    //     cout<<it<<' ';
    // }
    int save = 0;
    for (int i=0; i<min((int) arr.size(), s-1); i++){
        save += arr[i];
    }
    cout<<n-save;

    
    return 0;
}


/*
7 2
1 1 0 1 0 1 1
*/