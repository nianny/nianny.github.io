#include <bits/stdc++.h>
using namespace std;
#define int long long
#define hallo ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl '\n'
int n;
int arr[50010];
int c;
void merge(int st, int en){
   
    if (st == en) return;
    int mid = (st + en)/2;
    int sz = en - st + 1;

    merge(st, mid);
    merge(mid+1, en);

    int arr2[sz];
    int pos1 = st; //0
    int pos2 = mid+1; //1
    //cout<<st<<' '<<en<<' '<<mid<<' '<<pos1<<' '<<pos2<<'\n';

    for (int i=0; i<sz; i++){
        if (pos1>mid){
            arr2[i] = arr[pos2];
            pos2++;
        }
        else if (pos2 > en){
            arr2[i] = arr[pos1];
            pos1++;
        }
        else if (arr[pos1] <= arr[pos2]){
            arr2[i] = arr[pos1];
            pos1++;
        }
        else{
            arr2[i] = arr[pos2];
            c += pos2-i-st;
            
            //cout<<st<<' '<<en<<' '<<mid<<' '<<pos1<<' '<<pos2<<' '<<c<<' '<<i<<'\n';
            pos2++;
        }
    }

    for (int j = 0; j < sz; j++) arr[j + st] = arr2[j];
    /*
    for (int i=0; i<n; i++){
		cout<<arr[i]<<' ';
	}
	cout<<'\n';
	* */
	
}
int32_t main() {
    // ifstream cin("addin.txt");
    // ofstream cout("addout.txt");
    hallo;
    int t;
    cin>>t;
    for (int hmm = 0; hmm < t; hmm++){
        cin>>n;
        for (int i=0; i<n; i++){
            cin>>arr[i];
        }
        /*
        for (int i=0; i<n; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        * */
        
        c = 0;
        merge(0, n-1);
        cout<<c<<'\n';
        /*
        for (int i=0; i<n; i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        * */
        
    }
    
    return 0;
}
