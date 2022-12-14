#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef pair <int, int> pii;
typedef pair <int, bool> pib;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define rep(i,a,b) for (long long i=(a);i<(b);i++)
#define SZ(x) ((long long) (x).size())
#define pb push_back

int dx[]={0,0,1,-1,-1,-1,1,1}; //front 4 are not diagonal
int dy[]={1,-1,0,0,1,-1,-1,1};

const int mod=1e9+7;

int n,q,a,b;
char t;

pib arr[100005];

pib find(int x){
    if(arr[x].fi==x)return(MP(x,0));
    pib nx=find(arr[x].fi);
    if(nx.se==arr[x].se){
        arr[x]=MP(nx.fi,0);
    }else{
        arr[x]=MP(nx.fi,1);
    }
    return arr[x];
}

void merge(int a,int b,bool att){
    pib ax=find(a),bx=find(b);
    //att-ax.se-bx.se=000-0,111-1,100-1,010-1,001-1,110-0,101-0,011-0
    if(ax.fi==bx.fi)return;
    int total=ax.se+bx.se+att;
    if(total==0||total==2){
        arr[ax.fi]=MP(bx.fi,0);
    }else{
        arr[ax.fi]=MP(bx.fi,1);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    //freopen("ain.txt","r",stdin);
    //freopen("aout.txt","w",stdout);
    rep(i,0,100005){
        arr[i]=MP(i,0);
    }
    cin>>n>>q;
    rep(i,0,q){
        cin>>t>>a>>b;
        if(t=='A'){
            merge(a,b,1);
        }else if(t=='R'){
            merge(a,b,0);
        }else if(t=='Q'){
            pib ai=find(a),bi=find(b);
            if(ai.fi!=bi.fi){ //not same set leader
                cout<<"?\n";
            }else{
                if(ai.se==bi.se)cout<<"R\n";
                else cout<<"A\n";
            }
        }
    }
}