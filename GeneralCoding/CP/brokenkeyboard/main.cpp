#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n,k;
    cin>>n>>k;
    char str[n];
    set<int> avail;
    for (int i=0; i<n; i++){
        cin>>str[i];
    }
    for (int i=0; i<k; i++){
        char a;
        cin>>a;
        avail.insert(a);
    }

    vector<int> v;
    int count = 0;
    for (int i=0; i<n; i++){
        if (avail.find(str[i]) != avail.end()){
            count++;
        }
        else{
            v.push_back(count);
            count = 0;
        }
    }
    v.push_back(count);
    int sum=0;
    for (auto it:v){
        sum += it*(it+1)/2;
    }
    cout<<sum;
    return 0;
}