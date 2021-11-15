/*
you have a list of N operations which either *a_i or /a_i, where a_i is some nonzero integer.

You are given Q queries [l,r]. find the value of the math expression modulo M when concatenating the list of operations in [l,r] and adding "1" in front.

Note that M is a fixed number given at the start of the testcase.

You can show that the answer will be in the form of a p/q such that p and q are both positive integers. you should print a value of x such that x*q=p (mod m). if x exists, you can show that it is unique. otherwise, print -1.

N,Q<=1e6, M<=1e9 (not necessarily prime)
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
    int modulo;
    cin >> modulo;
    int modulostorage = modulo;
    int N, Q;
    //read input of N operations and store in array
    cin >> N;
    string a[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    //create prime factorization of modulo which are either *a_i or /a_i, where a_i is some nonzero integer.
    


    map<int,int> factors;
    int curr = 2;
    while(curr <= ceil(sqrt(modulo)) && modulo != 1){
        while (modulo % curr == 0){
            if (factors.find(curr)!=factors.end()){
                factors[curr] += 1;
            }
            else{
                factors[curr] = 1;
            }
            modulo /= curr;
        }
        curr++;
    }
    if (modulo != 1){
        if (factors.find(modulo)!=factors.end()){
                factors[modulo] += 1;
        }
        else{
            factors[modulo] = 1;
        }
    
    }
    //create prefix sum for each prime factor of modulo
    map<int,int> prefixsum;
    for (auto it = factors.begin(); it != factors.end(); it++){
        int curr = it->first;
        int curr_count = it->second;
        int curr_prefixsum = 0;
        for (int i = 0; i < curr_count; i++){
            curr_prefixsum += curr;
        }
        prefixsum[curr] = curr_prefixsum;
    }
    // input Q queries in the form of [l,r] and multiply the operations from index l to r inclusive. Factorize the resulting fraction in the form of the prime factors of the modulo and find the value of the fraction mod the modulo using the prefix array.
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        int numerator = 1;

        int denominator = 1;
        for (int j = l; j <= r; j++){
            //checks whether operation is multiplication or division by looking at first char
            if (a[j][0] == '*'){
                numerator *= stoi(a[j].substr(1,a[j].size()-1));
            }
            else{
                denominator *= stoi(a[j].substr(1,a[j].size()-1));
            }
            int num_dem_gcd = __gcd(numerator,denominator);
            numerator /= num_dem_gcd;
            denominator /= num_dem_gcd;
            //find the power of each prime factor of modulo in this fraction
            //evaluate the number of powers of each prime factor in numerator of fraction

        }
    }
}


