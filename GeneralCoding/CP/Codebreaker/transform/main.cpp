#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

const int intmax = 1e15;

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int l,n;
    cin>>l>>n;
    string a;
    cin>>a;
    
    int adjm[26][26];
    for (int i=0; i<26; i++){
        for (int p=0; p<26; p++){
            adjm[i][p] = intmax;

            if (i==p) adjm[i][p] = 0;
        }
    }
    for (int i=0; i<n; i++){
        char x,y;
        cin>>x>>y;
        int z;
        cin>>z;

        adjm[x-'a'][y-'a'] = min(adjm[x-'a'][y-'a'], z);
        // adjm[y-'a'][x-'a'] = min(adjm[y-]'a'][x-'a'], z);
        // cout<<x-'a'<<' '<<y-'a'<<' '<<adjm[x-'a'][y-'a']<<'\n';
    }

    // for (int i=0; i<26; i++){
    //     for (int p=0; p<26; p++){
    //         cout<<adjm[i][p]<<' ';
    //     }
    //     cout<<'\n';
    // }

    // for (int i=0; i<26; i++){
    //     for (int p=0; p<26; p++){
    //         if (adjm[i][p] != intmax){
    //             cout<<i<<' '<<p<<' '<<adjm[i][p]<<'\n';
    //         }
    //     }
    //     // cout<<'\n';
    // }

    for (int k=0; k<26; k++){
        for (int i=0; i<26; i++){
            for (int j = 0; j<26; j++){
                adjm[i][j] = min(adjm[i][j], adjm[i][k]+adjm[k][j]);
            }
        }
    }
    
    // cout<<adjm['c'-'a']['t'-'a']<<'\n';
    int sum = 0;
    for (int i=0; i<a.size()/2; i++){
        // cout<<i<<' '<<a[i]<<' '<<a[l-i-1]<<'\n';
        int first = a[i]-'a';
        int second = a[a.size()-i-1]-'a';
        
        int ans = intmax;
        for (int p=0; p<26; p++){
            ans = min(ans, adjm[first][p] + adjm[second][p]);
        }

        if (ans == intmax){
            cout << -1;
            return 0;
        }

        sum += ans;
    }

    cout<<sum;
    
    
    return 0;
}
