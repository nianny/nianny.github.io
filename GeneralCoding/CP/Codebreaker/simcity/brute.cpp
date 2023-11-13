#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int p[300005];
bool has_airport[300005];
int find(int x){
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int a, int b){
    p[find(a)] = find(b);
}

bool same_set(int a, int b){
    return find(a) == find(b);
}


int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;

    int n,r;
    cin>>n>>r;

    for (int i=0; i<n; i++){
        p[i] = i;
    }

    int D[n];
    for (int i=0; i<n; i++){
        cin>>D[i];
    }

    vector<pair<int,pair<int,int>>> v;
    for (int i=0; i<r; i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({c, {a,b}});
    }

    sort(v.begin(), v.end());
    int cost = 0;
    for (auto it: v){
        cout<<it.first<<' '<<it.second.first<<' '<<it.second.second<<'\n';
        if (has_airport[find(it.second.first)] && has_airport[find(it.second.second)]) continue;
        else if (has_airport[find(it.second.first)]){ //second boi does not have airport
            if (D[it.second.second] < it.first){//cheaper to build a new airport at second
                has_airport[it.second.second] = true;
                cost += D[it.second.second];
                cout<<"Build at "<<it.second.second<<'\n';
            }
            else{
                //cheaper to join them
                merge(it.second.second, it.second.first);
                cost += it.first;
                cout<<"Join "<<it.second.second<<" and "<<it.second.first<<'\n';
            }
        }
        else if (has_airport[find(it.second.second)]){//first boi does not have airport
            if (D[it.second.first] < it.first){//cheaper to build a new airport at first
                has_airport[it.second.first] = true;
                cost += D[it.second.first];
                cout<<"Build at "<<it.second.first<<'\n';
            }
            else{
                //cheaper to join them
                merge(it.second.first, it.second.second);
                cost += it.first;
                cout<<"Join "<<it.second.first<<" and "<<it.second.second<<'\n';
            }
        }
        else{
            //both no have airport
            if (it.first < min(D[it.second.first], D[it.second.second])){
                //cheaper to build road
                if (D[it.second.first] < D[it.second.second]){
                    has_airport[it.second.first] = true;
                    cost += D[it.second.first];
                    merge(it.second.second, it.second.first);
                    cost += it.first;
                    cout<<"Build airport at "<<it.second.first<<" and join "<<it.second.second<<" to "<<it.second.first<<'\n';
                }
                else{
                    has_airport[it.second.second] = true;
                    cost += D[it.second.second];
                    merge(it.second.first, it.second.second);
                    cost += it.first;
                    cout<<"Build airport at "<<it.second.second<<" and join "<<it.second.first<<" to "<<it.second.second<<'\n';
                }
            }
            else{
                //cheaper to build 2 airports
                has_airport[it.second.first] = true;
                cost += D[it.second.first];
                has_airport[it.second.second] = true;
                cost += D[it.second.second];
                cout<<"Build airport at "<<it.second.first<<" and "<<it.second.second<<'\n';
            }
        }
    }

    cout<<cost;
    /*
    Hallooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    */
    return 0;
}

