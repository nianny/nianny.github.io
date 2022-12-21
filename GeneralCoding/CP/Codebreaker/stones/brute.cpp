#include <bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
typedef pair <int, int> pii;
typedef pair <int, bool> pib;
typedef pair <int, pair <int, int> > pip;
typedef pair <pair <int, int>, int> ppi;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define rep(i,a,b) for (long long i=(a);i<(b);i++)
#define rrep(i,a,b) for (long long i=(a);i>(b);i--)
#define SZ(x) ((long long) sizeof(x))
#define pb push_back  

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fileinp freopen("ain.txt","r",stdin);freopen("aout.txt","w",stdout);

const int dx[]={1,-1,0,0,1,-1,-1,1};
const int dy[]={0,0,1,-1,-1,-1,1,1};

const int mod=1e9+7;
const int mod2=998244353;
const int INF=(int)1e18;
const int N=1000005;

int n,p,ans,root;
int stones[N],parent[N],subtree[N],substones[N];
vector<int>adjlist[N];

int sub(int x){
    int sum=1;
    for(auto it:adjlist[x]){
        if(it!=parent[x]){
            sum+=sub(it);
        }
    }
    subtree[x]=sum;
    return subtree[x];
}

int sub2(int x){
    int sum=stones[x];
    for(auto it:adjlist[x]){
        if(it!=parent[x]){
            sum+=sub2(it);
        }
    }
    substones[x]=sum;
    return substones[x];
}

signed main(){
    fastio;
    //fileinp;
    cin>>n;
    rep(i,0,n){
        cin>>p>>stones[i];
        if(p==-1){
            root=i;
        }
        parent[i]=p;
        if(p!=-1){
            adjlist[p].pb(i);
        }
    }
    sub(root);
    sub2(root);
    ans=0;
    rep(i,0,n){
        if(parent[i]!=-1){
            ans+=abs(subtree[i]-substones[i]);
            //cout<<i<<": "<<subtree[i]<<' '<<stones[i]<<'\n';
        }
    }
    cout<<ans;
    return 0;
}