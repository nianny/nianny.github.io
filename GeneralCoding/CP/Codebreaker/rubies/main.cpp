#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
#define double long double
struct node{
    int s,e,m;
    double val;
    node *l, *r;

    node(int _s, int _e){
        s=_s, e=_e, m=s+e>>1;
        val = 0;

        if (s != e){
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }

    void update(int X, double V){
        if (s == e) val = V;
        else{
            if (X <=m)l->update(X,V);
            else r->update(X,V);
            val = min(l->val, r->val);
        }
    }

    double query(int S, int E){
        if (s == S && e == E){
            return val;
        }
        else{
            if (E <=m) return l->query(S,E);
            else if (m<S) return r->query(S,E);
            else return min(l->query(S,m), r->query(m+1, E));
        }
    }
}*root = new node(0, 500010);
int n,l,h;
pair<int,int> arr[500010]; //cost, weight
bool possible(double x){
    double effect[n];
    for (int i=0; i<n; i++){
        effect[i] = arr[i].first - x*arr[i].second;
    }
    
    double ss[n+1];
    ss[0] = 0;
    for (int i=1; i<=n; i++){
        ss[i] = ss[i-1] + effect[i-1];
    }

    // for (int i=0; i<=n; i++){
    //     root->update(i, ss[i]);
    // }
    int left = 0;
    int right = 0;
    // int sum = 0;

    deque<pair<double,int>> dq;
    while (right <= n-l){
        while (!dq.empty() && dq.back().first > ss[right]){
            dq.pop_back();
        }
        dq.push_back({ss[right], right});

        while (!dq.empty() && dq.front().second < right-(h-l+1)) dq.pop_front();
        
        if (ss[right+l] >= dq.front().first) return true;
        right++;
    }

    // for (int i=l; i<=n; i++){
    //     if (ss[i] - root->query(max((int)0, i-h), i-l) >= 0) return true;
    // }

    return false;
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    double z=10e6;
    cout<<z;
    return 0;
    cin>>n>>l>>h;
    for (int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        arr[i] = {a,b};
    }
    double left, right, middle;
    left = 0;
    right = 10e6;
    int counter = 0;

    while (counter < 100){
        middle = (left+right)/2;
        counter++;
        //cout<<left<<' '<<right<<'\n';
        if (possible(middle)){
            left = middle;
        }
        else{
            right = middle;
        }
    }
    cout<<fixed<<setprecision(9);
    cout<<left;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    一剪寒梅傲立雪中
    只为伊人飘香
    */
    return 0;
}

