#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
pair<int,int> p[100010]; //second: 1 if diff from parent, 0 if same as parent
int dist[100010];
// vector<pair<int,int>>adjlist[n+5];
// vector<int>polarity[100010][2]; //0 is same as parent
pair<int,int> find_set(int x){
    if (p[x].first == x) return {p[x].first, 0};
    
    p[x] = find_set(p[x].first);
    // dist[x] = dist[p[x]];
    return p[x];
}

void merge_set(int a, int b, int pol){ //attract is 1, repel is 0
    pair<int,int> ap = find_set(a);
    pair<int,int> bp = find_set(b);

    if (ap.first == bp.first) return;
    p[ap.first] = {bp.first, (ap.second+bp.second+pol)%2};
}


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,q;
    cin>>n>>q;
    for (int i=0; i<=n; i++){
        p[i] = {i,0};
    }
    memset(dist, -1, sizeof dist);
    for (int i=0; i<q; i++){
        char t;
        int a,b;
        cin>>t>>a>>b;

        if (t == 'A'){
            merge_set(a,b,1);
        }
        else if (t == 'R'){
            merge_set(a,b,0);
        }
        else{
            auto pa = find_set(a);
            auto pb = find_set(b);

            if (pa.first != pb.first){
                cout<<"?"<<'\n';
            }
            else{
                if (pa.second == pb.second) cout<<'R'<<'\n';
                else cout<<'A'<<'\n';
            }
        }

    }
    
    return 0;
}
