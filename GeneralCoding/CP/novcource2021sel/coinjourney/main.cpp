#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n,q;
    cin>>n>>q;
    int arr[n];
    for (int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int ss[n];
    map<int,int> mp;
    vector<int> possibilities;
    ss[0] = arr[0];
    mp[arr[0]] = 1;
    int maximum = ss[0];
    for (int i=1; i<n; i++){
        ss[i] = ss[i-1] + arr[i];
        if (mp.find(ss[i]) == mp.end() && ss[i] > maximum && arr[i] > 0){
            mp[ss[i]] = i+1;
            maximum = max(maximum,ss[i]);
            possibilities.push_back(ss[i]);
        }
        
    }
    sort(possibilities.begin(), possibilities.end());

    for (int i=0; i<q; i++){
        int coins;
        cin>>coins;
        if (lower_bound(possibilities.begin(), possibilities.end(), coins) == possibilities.end()){
            cout<<-1<<' ';
        }
        else{
            cout<<mp[*lower_bound(possibilities.begin(), possibilities.end(), coins)]<<' ';
        }

        
        // bool flag = true;
        // for (int p=0; p<v.size(); p++){
        //     if (v[p].first >= coins){
        //         cout<<v[p].second+1<<" ";
        //         flag = false;
        //         break;
        //     }
        // }
        // if (flag){
        //     cout<<-1<<" ";
        // }
    }
    
    
    return 0;
}

/*
4 5
-5 9 3 9
1 5 7 6 10
*/