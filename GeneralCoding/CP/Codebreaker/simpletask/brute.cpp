#include <bits/stdc++.h>
using namespace std;
#define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
struct node	{
	int s,e,m;
	int val,lazy;
	node *l=nullptr, *r = nullptr; 
	
	node (int S, int E){
		s = S; e = E; m = (s + e)/2;
		val = 0;
		lazy = -1;
	}
	void create(){
		if (s != e){
			l = new node (s,m);
			r = new node (m+1, e);
		}
	}
	
    void propagate(){
        if (lazy == -1) return;
        
        val = lazy * (e-s+1);
        if (l==nullptr) create();
        
        if (s != e){
            l -> lazy = lazy; //???
            r -> lazy = lazy;
        }
        
        lazy=-1;
    }
	
	void update(int S, int E, int V){
		if (l==nullptr) create();
		propagate();
		if (s == S && e == E) lazy = V;
		else{
			if (E <= m) l-> update(S,E,V);
			else if (m < S) r->update(S,E,V);
			else l->update(S, m,V), r->update(m+1,E,V);
			
			l->propagate(), r->propagate();
			
			val = l->val + r->val;
		}
	}
	
	int query(int S, int E){
		if(l == nullptr) create();
		propagate();
        //cout<<s<<' '<<e<<' '<<lazy<<' '<<val<<'\n';
		
		if (s == S && e == E) {
            //cout<<s<<' '<<e<<' '<<lazy<<' '<<val<<'\n';
            return val;
        }
		else if (E<=m) return l->query(S,E);
		else if (m < S) return r->query(S,E);
		else return l->query(S,m) + r->query(m+1, E);
	}
} *root = new node(0, 10000);

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    kymchi;

    root -> update(0,10, 1);
    for (int i=0; i<20; i++){
        cout<<root -> query(i,i);
    }
    cout<<'\n';

    root -> update(1,4,0);
    for (int i=0; i<20; i++){
        cout<<root -> query(i,i);
    }
    cout<<'\n';
    
    return 0;
}