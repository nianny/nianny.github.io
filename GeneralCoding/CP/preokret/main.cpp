#include <bits/stdc++.h>
using namespace std;
#define int long long
#define speed ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'

int arr[2881];
int32_t main() {
    speed;
    int a,b;
    cin>>a;
    int min = 2881;
    bool isA;
    for (int i=0; i<a; i++){
        int hallo;
        cin>>hallo;
        arr[hallo] = 1;

        if (hallo < min){
            min = hallo;
            isA = true;
        }
    }

    cin>>b;
    for (int i=0; i<b; i++){
        int hallo;
        cin>>hallo;
        arr[hallo] = 2;

        if (hallo < min){
            min = hallo;
            isA = false;
        }
    }

    int part1 = 0;
    for (int i=1; i<=1440; i++){
        if (arr[i] != 0){
            part1++;
        }
    }
    cout<<part1<<'\n';
    int scoreA = 0, scoreB = 0;
    int sum = 0;
    for (int i=1; i<=2880; i++){
        if (arr[i] == 0) continue;
        if (arr[i] == 1){
            scoreA++;
        }
        else{
            scoreB++;
        }

        if (scoreA > scoreB && !isA){
            sum ++;
            isA = !isA;
        }
        else if (scoreB > scoreA && isA){
            sum ++;
            isA = !isA;
        }
    }
    cout<<sum;

    
    
    return 0;
}
