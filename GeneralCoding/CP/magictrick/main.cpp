#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    kymchi;
    int t;
    cin>>t;
    for (int i=0; i<t; i++){
        int a,b;
        cin>>a;
        int x[4][4];
        int y[4][4];
        for (int p=0; p<4; p++){
            for (int z = 0; z<4; z++){
                cin>>x[p][z];
            }
        }
        cin>>b;
        for (int p=0; p<4; p++){
            for (int z = 0; z<4; z++){
                cin>>y[p][z];
            }
        }

        set<int>words;
        for (auto it: x[a]){
            words.insert(it);
        }

        vector<int>ans;
        for (auto it: y[b]){
            if (words.find(it) != words.end()){
                
            }
        }
    }

    
    return 0;
}
