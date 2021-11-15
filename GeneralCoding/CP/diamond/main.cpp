#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;


    for (int i=0; i<n; i++){
        int num = i*2+1;
        int spaces = n-i-1;

        for (int p=0; p<spaces; p++){
            cout<<' ';
        }

        for (int p=0; p<num; p++){
            cout<<'*';
        }
        

        cout<<'\n';
    }


    for (int i=1; i<n; i++){
        for (int p=0; p<i; p++){
            cout<<' ';
        }

        int num = (n-i)*2-1;

        for (int p=0; p<num; p++){
            cout<<'*';
        }
        cout<<'\n';
    }
}