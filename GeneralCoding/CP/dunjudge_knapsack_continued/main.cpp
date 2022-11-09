#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int MAXN = 20000;
int s,n;
int w[MAXN];
int v[MAXN];
int memo[MAXN][2005];


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    cin>>s>>n;
    vector<int> arr[2005];
    for (int i=0; i<n; i++){
        int V,W,K;
        cin>>V>>W>>K;

        for (int i=0; i<K; i++){
            arr[W].push_back(V);
        }
    }

    for (int i=0; i<=2000; i++){
        sort(arr[i].begin(), arr[i].end(), greater<int>());
    }
    int count = 1;
    for (int i=1; i<=s; i++){
        for (int j=0; j<min(s/i, (long long)arr[i].size()); j++){
            w[count] = i;
            v[count] = arr[i][j];
            count++;
        }
    }
    for (int i=1; i<count; i++){
        for (int c=0; c <= s; c++){
            memo[i][c] = memo[i-1][c];
            if (c >= w[i]) memo[i][c] = max(memo[i][c], memo[i-1][c-w[i]] + v[i]);
            if (c > 0) memo[i][c] = max(memo[i][c], memo[i-1][c]);
        }
    }
    cout<<memo[count-1][s]<<endl;



    return 0;
}

/*
15 5
4 12 1
2 1 1
10 4 1
1 1 1
2 2 1
*/

/*
20 3
5000 15 1
100 1 3
50 1 4
*/

