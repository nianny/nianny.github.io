#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int counter = 0;
int pos = 0;
vector<int>parent;
pair<int,vector<int>>ele[2000010];
// int min_dp[2000010];
// int max_dp[2000010];
int ss[2000010];

void find_size(int x){
    if (ele[x].second.size() == 0) ss[x] = 1;
    else{
        find_size(ele[x].second[0]);
        find_size(ele[x].second[1]);

        ss[x] = ss[ele[x].second[0]] + ss[ele[x].second[1]];
    }
}

int min_range(int x){
    if (ele[x].second.size() == 0) return 1; //?
    
    if (ele[x].first == 0){ //min query
        return min(min_range(ele[x].second[0]), min_range(ele[x].second[1]));
    }
    else{
        return min_range(ele[x].second[0]) + min_range(ele[x].second[1]);
    }
}

int max_range(int x){
    if (ele[x].second.size() == 0) return 1; //?
    
    if (ele[x].first == 0){ //min query
        return max_range(ele[x].second[0]) + max_range(ele[x].second[1]) -1;
    }
    else{
        int a = ele[x].second[0];
        int b = ele[x].second[1];

        return max(ss[a]+max_range(b), ss[b]+max_range(a));
    }
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    // memset(min_dp, -1, sizeof min_dp);
    // memset(max_dp, -1, sizeof max_dp);
    
    string a;
    cin>>a;
    parent.push_back(counter);
    counter++; // 1 indexed

    

    while (pos < a.length()){
        if (a[pos] == 'm'){
            if (a[pos+1] == 'i'){ //min operation
                ele[parent.back()].second.push_back(counter);
                ele[counter].first = 0;
                pos += 3;
                parent.push_back(counter);
                counter++;
            }
            else {
                ele[parent.back()].second.push_back(counter);
                ele[counter].first = 1;
                pos += 3;
                parent.push_back(counter);
                counter++;
            }
        }
        else if (a[pos] == '?'){
            ele[parent.back()].second.push_back(counter);
            counter++;
            // ele[counter].first = 0;
            // pos += 3;
        }
        else if (a[pos] == ')'){
            parent.pop_back();
        }

        // counter++;
        pos++;
    }
    // cout<<counter<<' '<<pos<<'\n';

    // for (int i=0; i<10; i++){
    //     cout<<i<<'\t';
    //     cout<<ele[i].first<<'\t';
    //     for (auto x:ele[i].second){
    //         cout<<x<<' ';
    //     }
    //     cout<<'\n';
    // }

    // cout<<ele[0].first<<' '<<ele[0].second.first<<' '<<ele[0].second.second;
    find_size(1);
    // for (int i=0; i<10; i++){
    //     cout<<ss[i]<<' ';
    // }
    // cout<<'\n';
    // cout<<min_range(1)<<' '<<max_range(1);
    cout<<max_range(1) - min_range(1) +1;
    
    /*
    雪花飘飘北风萧萧
    天地一片苍茫
    */
    return 0;
}

