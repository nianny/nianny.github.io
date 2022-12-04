#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int p[100010];

int find_set(int a){
    if (p[a] == a) return a;
    p[a] = find_set(p[a]);
    return p[a];
}

bool same_set(int a, int b){
    return find_set(a) == find_set(b);
}

void merge_set(int a, int b){
    p[find_set(a)] = find_set(b);
}

int calc(int x){
    return x*(x+1)/2;
}

int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int n,q;
    cin>>n>>q;
    int arr[n];
    for (int i=0; i<n; i++){
        cin>>arr[i];
    }

    for (int i=0; i<=n; i++){
        p[i] = i;
    }
    vector<pair<int,int>>query;
    for (int i=0; i<q; i++){
        int a;
        cin>>a;
        query.push_back({a,i});
    }

    sort(query.begin(), query.end());
    

    vector<pair<int,int>> output;
    // for (auto i: query){
    //     cout<<i.first<<'\n';
    // }
    int total = 1;
    for (auto i: query){
        // cout<<i.first<<'\n';
        int current = 0;
        // current = find_set(current);
        while (current<n){
            // cout<<current<<' ';
            if (arr[find_set(current)] <= i.first){
                // cout<<"MERGED "<<current<<' '<<find_set(current)+1<<'\n';
                // cout<<current<<' '<<find_set(current) + 1<<' '<<find_set(find_set(current)+1)<<' '<<find_set(find_set(current)+1) - find_set(current)+1<<' '<<total<<'\n';

                // cout<<calc(find_set(find_set(current)+1) - current)<<' '<<calc(find_set(current) - current)<<' '<<calc(find_set(find_set(current)+1) - (find_set(current)+1)) <<'\n';

                total = total + calc(find_set(find_set(current)+1) - current) - calc(find_set(current) - current) - calc(find_set(find_set(current)+1) - (find_set(current)+1));
                // cout<<current<<' '<<current+1<<' '<<find_set(current)<<' '<<arr[find_set(current)]<<'\n';
                merge_set(find_set(current), find_set(current)+1); 
                
                current = find_set(current);
                // for (int j=0; j<=n; j++){
                //     cout<<find_set(j)<<' ';
                // }
                // cout<<'\n';
            }
            else{
                // cout<<"ADDED "<<current<<' '<<find_set(current+1)<<'\n';

                // for (int j=0; j<=n; j++){
                //     cout<<p[j]<<' ';
                // }
                // cout<<'\n';
                current = find_set(current+1);
                // cout<<current<<'\n';
            }
            
        }

        // for (int j=0; j<=n; j++){
        //     cout<<find_set(j)<<' ';
        // }
        // cout<<'\n';

        // int total = 0;
        // current = 0;
        // while (current <= n){
        //     // cout<<current<<' ';
        //     int diff = find_set(current) - current;
        //     current = find_set(current) + 1;
        //     total += (diff)*(diff+1)/2;
        // }

        output.push_back({i.second, total});
    }

    sort(output.begin(), output.end());

    for (auto i: output){
        cout<<i.second<<'\n';
    }
    // cout<<"HALOL";
    
    
    return 0;
}
