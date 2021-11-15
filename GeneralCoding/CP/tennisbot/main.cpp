#include <bits/stdc++.h>

    int b,n;using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    cin>>b>>n;
    vector<pair<int,int>> v;
    for (int i=0; i<b; i++){
        int a;
        cin>>a;
        v.push_back(make_pair(a,i));
    }

    sort(v.begin(),v.end(), greater<pair<int,int>>());


    while (n>0){

    }
    for (auto it:v){
        cout<<it.second+1<<" "<<it.first<<endl;
    }

    
    
    
    return 0;
}
