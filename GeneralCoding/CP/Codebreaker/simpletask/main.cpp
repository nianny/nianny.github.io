#include <bits/stdc++.h>
using namespace std;
#define int long long


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
};


int32_t main(){
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
	int n,q;
	cin>>n>>q;
	char arr[n+5];
	for (int i=1; i<=n; i++){
		cin>>arr[i];
	}
	
	node* hallo[26];
	for (int i=0; i<26; i++){
		hallo[i] = new node(0, 100010);
	}
	
	
	for (int i=1; i<=n; i++){
		hallo[arr[i]-'a']->update(i,i,1);
	}
	
	for (int i=0; i<q; i++){
		int l,r,k;
		cin>>l>>r>>k;

        // if (i > 0) continue;
		
		
		int freq[26];
		memset(freq, 0, sizeof freq);
		for (int j=0; j<26; j++){
			freq[j] = hallo[j]->query(l,r);
			hallo[j]->update(l,r,0);
		}
		// cout<<l<<' '<<r<<' '<<k<<'\n';
		// for (int j=0; j<26; j++){
		// 	cout<<j<<'\t';
		// 	for (int p=1; p<=n; p++){
		// 		cout<<hallo[j]->query(p,p);
		// 	}
		// 	cout<<'\n';
		// }
		
		
		
		int current = l;
		if (k==0){
			for (int j=25; j>=0; j--){
				//cout<<l<<' '<<r<<' '<<current<<'\n';
				//assert(current+freq[j]-1 <=n);
				if (freq[j] == 0) continue;
				hallo[j]->update(current, current+freq[j]-1,1);
				current+=freq[j];
			}
		}
		else{
			for (int j=0; j<26; j++){
				//cout<<l<<' '<<r<<' '<<current<<'\n';
				//assert(current+freq[j]-1 <=n);
				if (freq[j] == 0) continue;
				hallo[j]->update(current, current+freq[j]-1,1);
				current+=freq[j];
			}
		}
		
		// char ans[n+5];
		// for (int i=1; i<=n; i++){
		// 	for (int j=0; j<26; j++){
		// 		if (hallo[j]->query(i,i)){
		// 			ans[i] = (char)(j+'a');
		// 			break;
		// 		}
		// 	}
		// }
		
		// for (int i=1; i<=n; i++){
		// 	cout<<ans[i];
		// }
		// cout<<'\n';
		
	}
	
	char ans[n+5];
	for (int i=1; i<=n; i++){
		for (int j=0; j<26; j++){
			if (hallo[j]->query(i,i)){
				ans[i] = (char)(j+'a');
				break;
			}
		}
	}
	
	for (int i=1; i<=n; i++){
		cout<<ans[i];
	}
	cout<<'\n';
	
	// for (int j=0; j<26; j++){
	// 	cout<<j<<'\t';
	// 	for (int p=1; p<=n; p++){
	// 		cout<<hallo[j]->query(p,p);
	// 	}
	// 	cout<<'\n';
	// }
	
	
}
