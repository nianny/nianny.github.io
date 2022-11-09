#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
vector<int> adjList[1005];

bool dfs(int x){
    if (adjList[x].size() == 0) return true;
    int counter = 0;
    for(int i = 0; i < adjList[x].size(); i++){
        if(!dfs(adjList[x][i])){
            return false;
        }
        if (adjList[adjList[x][i]].size() == 0){    
            counter ++;
        }
    }
    if(counter >= 3){
        return true;
    }
    else {
        return false;
    }
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n;
    cin>>n;
    
    for (int i=2; i<=n; i++){
        int x;
        cin>>x;
        adjList[x].push_back(i);
    }

    if(dfs(1)){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    
    return 0;
}
