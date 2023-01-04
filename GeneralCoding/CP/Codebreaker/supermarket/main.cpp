#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

//peepeepoopoo
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,x;
    cin>>n>>x;
    int D[n+5];
    int W[n+5];
    for (int i=1; i<=n; i++){
        cin>>D[i];
    }

    for (int i=1; i<=n; i++){
        cin>>W[i];
    }
    int deli[n+5];
    int weig[n+5];
    // ss[0] = D[0];
    deli[0] = 0;
    weig[0] = 0;
    for (int i=1; i<=n; i++){
        deli[i] = deli[i-1]+D[i];
        weig[i] = weig[i-1]+ W[i];
    }

    // int l=1;
    int r=1;

    // int sum = 0;
    // deque<int>dq;

    // while(r <= n+1){

    // }
    int rightishpotato[n+5];
    rightishpotato[0] = 0;
    for (int l=1; l<=n; l++){
        while (r <= n && weig[r]-weig[l-1] <= x){
            r++;
        }

        rightishpotato[l] = r-1;
    }

    // for (int i=0; i<=n; i++){
    //     cout<<rightishpotato[i]<<' ';
    // }
    // cout<<'\n';

    stack<int*>badboipotatohmm;
    badboipotatohmm.push(rightishpotato);
    deque<int>peepeepoopoo;
    int ans = 0;
    for (int i=1; i<=n; i++){
        for (int x = rightishpotato[i-1]+1; x <= rightishpotato[i]; x++){
            while(!peepeepoopoo.empty() and deli[peepeepoopoo.back()] < deli[x]) peepeepoopoo.pop_back();
            peepeepoopoo.push_back(x);
        }

        while(!peepeepoopoo.empty() and peepeepoopoo.front() < i) peepeepoopoo.pop_front(); 

        ans = max(ans, deli[peepeepoopoo.front()]-deli[i-1]);
    }
    cout<<ans;
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

