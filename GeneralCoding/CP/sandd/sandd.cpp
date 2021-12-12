#include <bits/stdc++.h>
// #include <iostream>
#include "sandd.h"
using namespace std;
// #define int long long
#define kymchi ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define endl '\n'

bool tooHigh (int a){
    return supply(a) > demand(a);
}

int getPrice (int P){

    int low = 0;
    int high = P;

    while (high - low > 1){
        int mid = (low + high) / 2;

        if (tooHigh(mid)){
            low = mid;
        }
        else{
            high = mid;
        }

    }
    return low;
}

