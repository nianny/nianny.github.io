#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> disc(vector <int> V) {
	vector <int> dis = V;
	sort(dis.begin(),dis.end());
	dis.resize(unique(dis.begin(),dis.end()) - dis.begin());
	for (int i =0;i<(int)V.size();i++) {
		V[i] = lower_bound(dis.begin(),dis.end(),V[i]) - dis.begin() + 1;
	}
	return V;
}

struct node {
    int s,e,m,v;
    node *l=nullptr, *r=nullptr;
    node (int _s, int _e){
        s = _s, e = _e, m = (s+e)/2;
        v = 0;

    }

    void create(){
        if (s!=e){
            l = new node (s,m);
            r = new node (m+1, e);
        }
    }

    int query(int S, int E){
        if(l == nullptr) create();

        if (s==S && e==E){
            return v;
        }
        if (E<=m) return l->query(S,E);
        if (S>m) return r->query(S,E);
        return max(l->query(S,m), r->query(m+1,E));
    }

    void update(int S, int V){
        if (s==e) { v=V; return;}
        else{
            if(l == nullptr) create();

            if (S>m){
                r->update(S, V);
            }
            if (S<=m) l->update(S,V);
            v = max(l->v, r->v);
        }
    }
} *root;

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    
    int n;
    cin>>n;
    vector<int> arr;
    int maximum = 0;
    for (int i=0; i<n; i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    arr = disc(arr);
    root = new node (0, n + 3);
    maximum = 0;
    for (int i=0; i<n; i++){
        int v = root->query(0, arr[i]-1) + 1;
        maximum = max(maximum, v);
        root->update(arr[i], v);
    }

    cout<<maximum;

    return 0;
}