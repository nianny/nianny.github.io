#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int memo[400][400][400][3];

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    // string s;
    cin>>n;
    vector<int>count[3];


    for (int i=0; i<n; i++){
        char a;
        cin>>a;
        int indicator = 0;
        if (a=='R') indicator = 0;
        else if (a=='G') indicator = 1;
        else indicator = 2;

        count[indicator].push_back(i);
    }
    
    
    for (int x=0; x<count[0].size(); x++){
        for (int y=0; y<count[1].size(); y++){
            for (int z = 0; z<count[2].size(); z++){
                for (int last_colour = 0; last_colour < 3; last_colour++){
                    if (x==0 && y==0 && z==0){
                        memo[x][y][z][last_colour] = 0;
                        continue;
                    }
                    if(last_colour==0 && x==0 || last_colour == 1 && y==0 || last_colour==2 && z==0){
                        memo[x][y][z][last_colour] = 1e18;
                        continue;
                    }

                    int res = 1e18;
                    
                }
            }
        }
    }


    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

