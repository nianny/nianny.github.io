#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int freq[1000005];
int ans[200005];
int nums[200005];
int n, q;
int block;

struct Query{
    int s,e,i;
};
int comp (Query a, Query b){
    return (a.s/block != b.s/block ? a.s/block < b.s/block : a.e < b.e);
}

int currL = 1, currR = 1;
int currAns = 0;

int query(int s, int e){
    while (currL < s){
        freq[nums[currL]]--;
        if (freq[nums[currL]] == 0) currAns--;
        currL++;
    }

    while (currL > s){
        currL--;
        freq[nums[currL]]++;
        if (freq[nums[currL]] == 1) currAns++;
    }

    while (currR <= e){
        freq[nums[currR]]++;
        if (freq[nums[currR]] == 1) currAns++;
        currR++;
    }

    while (currR > e+1){
        currR--;
        freq[nums[currR]]--;
        if (freq[nums[currR]] == 0) currAns--;
    }

    return currAns;
}



vector<Query> queries;
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;
    cin>>n;
    block = 600;

    for (int i=1; i<=n; i++){
        cin>>nums[i];
    }

    cin>>q;

    for (int i=0; i<q; i++){
        int a,b;
        cin>>a>>b;
        queries.push_back({a, b, i});
    }

    sort(queries.begin(), queries.end(), comp);
 
    for (auto i: queries){
        ans[i.i] = query(i.s, i.e);
        // cout<<i.i<<' '<<i.s<<' '<<i.e<<' '<<ans[i.i]<<endl;
    }

    for (int i=0; i<q; i++){
        cout<<ans[i]<<endl;
    }

    
    return 0;
}
