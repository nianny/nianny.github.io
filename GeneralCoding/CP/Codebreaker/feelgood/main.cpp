#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
// #define endl '\n'
int MOD = 1e9+7;
int A;
string a,b;
string s;
int high_ans[10];
int low_ans[10];
vector<int> memo[18][2][2];

int parse_string(string s, int x){
    string sx = s.substr(x+1, s.size()-x-1);
    if (sx==""){
        return 0;
    }
    return stoi(sx);
}

int expo (int x){
    int add = 1;
    for (int j=0; j<x; j++){
        add *= 10;
        add %= MOD;
    }
    return add;
}

vector<int> add_nums (vector<int> a, vector<int> b){
    vector<int> ans(10);
    for (int i=0; i<10; i++){
        ans[i] = (a[i] + b[i])%MOD;
    }
    return ans;
}

vector<int> dp(int no_of_digits, bool has_been_0, bool is_bounded){
    if (memo[no_of_digits][has_been_0][is_bounded].size() != 0){
        return memo[no_of_digits][has_been_0][is_bounded];
    }
}

void high(int no_of_digits, bool has_been_0, bool is_bounded){
    if (no_of_digits >= 18){
        return;
    }
    if (is_bounded){
        if (has_been_0){
            if (b[no_of_digits]!='0'){
                high(no_of_digits+1, true, false);
                
                for (int i=1; i<b[no_of_digits]-'0'; i++){
                    high_ans[i] += expo(17-no_of_digits);
                    high_ans[i] %= MOD; 
                    high(no_of_digits+1, false, false);
                }
                high_ans[b[no_of_digits]-'0'] += parse_string(b, no_of_digits)+1;
                high(no_of_digits+1, false, true);
            }
            else{
                high(no_of_digits+1, true, true);
            }
        }
        else{
            
            for (int i=0; i<b[no_of_digits]-'0'; i++){
                high_ans[i] += expo(17-no_of_digits);
                high_ans[i] %= MOD; 
                high(no_of_digits+1, false, false);
            }
            high_ans[b[no_of_digits]-'0'] += parse_string(b, no_of_digits)+1;
            high(no_of_digits+1, false, true);
        }
    }
    else{
        if (has_been_0){
            high(no_of_digits+1, true, false);

            for (int i=1; i<10; i++){
                high_ans[i] += expo(17-no_of_digits);
                high_ans[i] %= MOD;
                high(no_of_digits+1, false, false);
            }
        }
        else {
            for (int i=0; i<10; i++){
                high_ans[i] += expo(17-no_of_digits);
                high_ans[i] %= MOD;
                high(no_of_digits+1, false, false);
            }
            
        }
    }
}

void low(int no_of_digits, bool has_been_0, bool is_bounded){
    if (no_of_digits >= 18){
        return;
    }
    if (is_bounded){
        if (has_been_0){
            if (a[no_of_digits]!='0'){
                low(no_of_digits+1, true, false);
                
                for (int i=1; i<a[no_of_digits]-'0'; i++){
                    low_ans[i] += expo(17-no_of_digits);
                    low_ans[i] %= MOD; 
                    low(no_of_digits+1, false, false);
                }
                low_ans[a[no_of_digits]-'0'] += parse_string(a, no_of_digits)+1;
                low(no_of_digits+1, false, true);
            }
            else{
                low(no_of_digits+1, true, true);
            }
        }
        else{
            
            for (int i=0; i<a[no_of_digits]-'0'; i++){
                low_ans[i] += expo(17-no_of_digits);
                low_ans[i] %= MOD; 
                low(no_of_digits+1, false, false);
            }
            low_ans[a[no_of_digits]-'0'] += parse_string(a, no_of_digits)+1;
            low(no_of_digits+1, false, true);
        }
    }
    else{
        if (has_been_0){
            low(no_of_digits+1, true, false);

            for (int i=1; i<10; i++){
                low_ans[i] += expo(17-no_of_digits);
                low_ans[i] %= MOD;
                low(no_of_digits+1, false, false);
            }
        }
        else {
            for (int i=0; i<10; i++){
                low_ans[i] += expo(17-no_of_digits);
                low_ans[i] %= MOD;
                low(no_of_digits+1, false, false);
            }
            
        }
    }
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    cin>>A>>b;
    A -= 1;
    a = to_string(A);
    a = string(18-a.length(), '0')+a;
    b = string(18-b.length(), '0')+b;
    vector<int> empty;
    for (int i=0; i<18; i++){
        for (int j=0; j<4; j++){
            memo[i][j%2][(j/2)%2] = empty;
        }
    }
    // cout<<b<<'\n';
    high(0, true, true);
    low(0, true, true);
    for (int i=0; i<10; i++){
        cout<<high_ans[i]-low_ans[i]<<"\n";
    }
    // cout<<'\n';
    // for (int i=0; i<10; i++){
    //     cout<<high_ans[i]<<" ";
    // }
    // cout<<'\n';
    // for (int i=0; i<10; i++){
    //     cout<<low_ans[i]<<" ";
    // }
    // cout<<parse_string(b,0)<<endl;
    
    return 0;
}
