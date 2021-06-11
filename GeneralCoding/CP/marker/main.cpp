#include <bits/stdc++.h>
using namespace std;
#define int long long

bool grade(int a, int b, int ans, char operate){
    if (operate == '+'){
        return (a+b) == ans;
    }
    else if (operate == '-'){
        return (a-b) == ans;
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0); 
    int n;
    cin>>n;
    int bob = 0, patrick = 0;
    for (int i=0; i<n; i++){
        int a,b,ans;
        char operate,spacer;
        cin>>a>>operate>>b>>spacer>>ans;
        if (grade(a,b,ans,operate)){
            bob++;
        }
    }
    for (int i=0; i<n; i++){
        int a,b,ans;
        char operate, spacer;
        cin>>a>>operate>>b>>spacer>>ans;
        if (grade(a,b,ans,operate)){
            patrick++;
        }
    }

    cout<<"Spongebob: "<<bob<<'\n';
    cout<<"Patrick: "<<patrick;
    return 0;
}
