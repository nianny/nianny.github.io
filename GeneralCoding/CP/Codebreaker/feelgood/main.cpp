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
vector<int> memo[20][2][2];
vector<int> empty_v;

int parse_string(string s, int x){
    string sx = s.substr(x+1, s.size()-x-1);
    if (sx==""){
        return 0;
    }
    return stoll(sx)%MOD;
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
    if(no_of_digits >= 20){
        vector<int> zero_vector;
        for (int i=0; i<10; i++){
            zero_vector.push_back(0);
        }
        return zero_vector;
    }
    if (memo[no_of_digits][has_been_0][is_bounded].size() != 0){
        return memo[no_of_digits][has_been_0][is_bounded];
    }
    for (int i=0; i<10; i++){
        memo[no_of_digits][has_been_0][is_bounded].push_back(0);
    }
    if (is_bounded){
        if (has_been_0){
            if (s[no_of_digits] != '0'){
                memo[no_of_digits][has_been_0][is_bounded]=add_nums(memo[no_of_digits][has_been_0][is_bounded], dp(no_of_digits+1, true, false));
                for (int i=1; i<s[no_of_digits]-'0'; i++){
                    memo[no_of_digits][has_been_0][is_bounded][i] += expo(19-no_of_digits);
                    memo[no_of_digits][has_been_0][is_bounded][i] %= MOD; 
                    memo[no_of_digits][has_been_0][is_bounded] = add_nums(memo[no_of_digits][has_been_0][is_bounded], dp(no_of_digits+1, false, false));
                }
                memo[no_of_digits][has_been_0][is_bounded][s[no_of_digits]-'0'] += (parse_string(s, no_of_digits)+1)%MOD;
                memo[no_of_digits][has_been_0][is_bounded] = add_nums(memo[no_of_digits][has_been_0][is_bounded], dp(no_of_digits+1, false, true));
            }
            else{
                memo[no_of_digits][has_been_0][is_bounded] = add_nums(memo[no_of_digits][has_been_0][is_bounded], dp(no_of_digits+1, true, true));
            }
        }
        else {
            for (int i=0; i<s[no_of_digits]-'0'; i++){
                memo[no_of_digits][has_been_0][is_bounded][i] += expo(19-no_of_digits);
                memo[no_of_digits][has_been_0][is_bounded][i] %= MOD; 
                memo[no_of_digits][has_been_0][is_bounded] = add_nums(memo[no_of_digits][has_been_0][is_bounded], dp(no_of_digits+1, false, false));
            }
            memo[no_of_digits][has_been_0][is_bounded][s[no_of_digits]-'0'] += (parse_string(s, no_of_digits)+1)%MOD;
            memo[no_of_digits][has_been_0][is_bounded] = add_nums(memo[no_of_digits][has_been_0][is_bounded], dp(no_of_digits+1, false, true));
        }
    }
    else{
        if (has_been_0){
            memo[no_of_digits][has_been_0][is_bounded] = add_nums(memo[no_of_digits][has_been_0][is_bounded], dp(no_of_digits+1, true, false));
            for (int i=1; i<10; i++){
                memo[no_of_digits][has_been_0][is_bounded][i] += expo(19-no_of_digits);
                memo[no_of_digits][has_been_0][is_bounded][i] %= MOD;
                memo[no_of_digits][has_been_0][is_bounded] = add_nums(memo[no_of_digits][has_been_0][is_bounded], dp(no_of_digits+1, false, false));
            }
        }
        else{
            for (int i=0; i<10; i++){
                memo[no_of_digits][has_been_0][is_bounded][i] += expo(19-no_of_digits);
                memo[no_of_digits][has_been_0][is_bounded][i] %= MOD;
                memo[no_of_digits][has_been_0][is_bounded] = add_nums(memo[no_of_digits][has_been_0][is_bounded], dp(no_of_digits+1, false, false));
            }
        }
    }
    return memo[no_of_digits][has_been_0][is_bounded];
}

void high(int no_of_digits, bool has_been_0, bool is_bounded){
    if (no_of_digits >= 20){
        return;
    }
    if (is_bounded){
        if (has_been_0){
            if (b[no_of_digits]!='0'){
                high(no_of_digits+1, true, false);
                
                for (int i=1; i<b[no_of_digits]-'0'; i++){
                    high_ans[i] += expo(19-no_of_digits);
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
                high_ans[i] += expo(19-no_of_digits);
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
                high_ans[i] += expo(19-no_of_digits);
                high_ans[i] %= MOD;
                high(no_of_digits+1, false, false);
            }
        }
        else {
            for (int i=0; i<10; i++){
                high_ans[i] += expo(19-no_of_digits);
                high_ans[i] %= MOD;
                high(no_of_digits+1, false, false);
            }
            
        }
    }
}

void low(int no_of_digits, bool has_been_0, bool is_bounded){
    if (no_of_digits >= 20){
        return;
    }
    if (is_bounded){
        if (has_been_0){
            if (a[no_of_digits]!='0'){
                low(no_of_digits+1, true, false);
                
                for (int i=1; i<a[no_of_digits]-'0'; i++){
                    low_ans[i] += expo(19-no_of_digits);
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
                low_ans[i] += expo(19-no_of_digits);
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
                low_ans[i] += expo(19-no_of_digits);
                low_ans[i] %= MOD;
                low(no_of_digits+1, false, false);
            }
        }
        else {
            for (int i=0; i<10; i++){
                low_ans[i] += expo(19-no_of_digits);
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
    a = string(20-a.length(), '0')+a;
    b = string(20-b.length(), '0')+b;
    for (int i=0; i<20; i++){
        for (int j=0; j<4; j++){
            memo[i][j%2][(j/2)%2] = empty_v;
        }
    }
    s = a;
    vector<int> a_ans = dp(0, true, true);


    for (int i=0; i<20; i++){
        for (int j=0; j<4; j++){
            memo[i][j%2][(j/2)%2] = empty_v;
        }
    }
    s = b;
    vector<int> b_ans = dp(0, true, true);
    for (int i=0; i<10; i++){
        cout<<(b_ans[i] - a_ans[i]+MOD)%MOD<<"\n";
    }
    // cout<<'\n';
    // for (int i=0; i<10; i++){
    //     cout<<a_ans[i]<<' ';
    // }
    // cout<<'\n';
    // for (int i=0; i<10; i++){
    //     cout<<b_ans[i]<<' ';
    // }
    // cout<<'\n';

    // cout<<b<<'\n';
    // high(0, true, true);
    // low(0, true, true);
    // for (int i=0; i<10; i++){
    //     cout<<high_ans[i]-low_ans[i]<<"\n";
    // }
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
