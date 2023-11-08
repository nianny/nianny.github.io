#include <bits/stdc++.h>
using namespace std;
struct node{ 
    int s,e,m; //range [s,e]. m is the midpoint 
    int val; //minumum value of [s,e]
    node *l, *r; //create children (something called pointers)

    node (int S, int E){ // input the variables that we need (called a constructor)
        s = S, e=E, m=(s+e)/2;
        val=0; //maximum possible value (so it always goes down)

        if (s != e){ //if not leaf (one number), create two children
            l = new node(s,m); //left child
            r = new node(m+1,e); //right child
        }
    }

    void update(int X, int V){ //change the X value to V
        if (s==e) val = V; //if node has only one thingi (leaf), replace the value with the changed number

        else{//find the lead
            if (X<=m) l->update(X,V); //x is on the left side (do something that goes down to the bottom left children)
            else r->update(X,V); //on the right side, do something that goes to the right side

            val=(l->val + r->val); //find minimum of the two cvhildren, which is the mimuimum of the children of the children and so on
        }
    }

    int query(int S, int E){//S=start of query, E=end of query
        if (s==S && e==E) return val; //case 1: basiclaly of the entire segment tree (start to end), just read from the top most parent
        else if (E<=m) return l->query(S,E); //case 2: when the last thing is all on the left side 
        else if (S>=m+1) return r->query(S,E); //case 3: everything on right, query the right children for the start to the end
        else return (l->query(S,m) + r->query(m+1, E)); //case 4: splits the query into the two parts for eachj children and query, consolidate the results later
    }
} *root;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,q;
    cin>>n;
    root = new node(0,n);
    for (int i=1; i<=n; i++){
        int a;
        cin>>a;
        root->update(i,a);
    }

    cin>>q;
    for (int i=0; i<q; i++){
        int num;
        cin>>num;
        if (num==1){
            int P,V;
            cin>>P>>V;

            root->update(P,V);
        }
        else{
            int S,E;
            cin>>S>>E;
            cout<<root->query(S,E)<<'\n';
        }
    }
}