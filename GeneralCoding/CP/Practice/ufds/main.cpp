#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int p[10000010];
int find_set(int x){
    if (p[x] == x) return x;
    p[x] = find_set(p[x]);
    return p[x];
}

void merge_set(int a, int b){
    p[find_set(a)] = find_set(b);
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,c;
    cin>>n>>c;

    for (int i=1; i<=n; i++){
        p[i] = i;
    }
    for (int i=0; i<c; i++){
        int a;
        cin>>a;
        cout<<find_set(a)<<'\n';
        if (find_set(a) == 1) merge_set(find_set(a), find_set(n));
        else merge_set(find_set(a), find_set(a)-1);
    }
    return 0;
}
