#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    int n, h;
    cin>>n>>h;
    multiset<int> s;
    int arr[h];
    for (int i=0; i<h; i++){
        arr[i] = 0;
        s.insert(0);
    }
    
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        if (a == 1){
            // if (arr[b%h] == 0){
            //     s.insert(1);
            //     arr[b%h] = 1;
            // }
            // else {
            s.erase(s.find(arr[b%h]));
            arr[b%h]++;
            s.insert(arr[b%h]);
            // }
        }
        else {
            // if (arr[b%h] == 1) {
            //     s.erase(s.find(arr[b%h]));
            //     arr[b%h]--;
            // }
            // else {
            s.erase(s.find(arr[b%h]));
            arr[b%h]--;
            s.insert(arr[b%h]);
            // }
        }
        // for (int p=0; p<h; p++){
        //     cout<<arr[p]<<" ";
        // }
        // cout<<'\t';

        // for (auto it: s){
        //     cout<<it<<" ";
        // }
        // cout<<'\t';


        if (s.empty()){
            cout<<"O"<<'\n';
        }
        else{
            cout<<*(--s.end())<<"\n";
        }

        
    }
    
    
    return 0;
}
