#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'

bool comp(pair<int,int> a, pair<int,int> b){

    int x,y;
    x = a.first;
    y = b.first;

    x *= (b.second);
    y *= (a.second);

    return x < y;




    // retu rn ((double)a.first/a.second) < ((double)b.first/b.second);

    // return a.first < b.first;
}


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    // cout<<(double)1/3<<endl;

    // cout<<(double)2/6<<endl;


    // if (((double)1/3) >= ((double)101/300)) {
    //     cout<<"yes"<<endl;
    // } else {
    //     cout<<"no"<<endl;
    // }

    int n;
    cin>>n;

    pair<int,int> arr[n];

    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;

        arr[i] = make_pair(a,b);
    }

    stable_sort (arr, arr+n, comp);

    for (int i=0; i<n; i++){
        cout<<arr[i].first<<" "<<arr[i].second<<endl;
    }



    
    
    return 0;
}
