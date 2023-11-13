#include <bits/stdc++.h>
using namespace std;
#define int long long

int N,K,A[5000005];
signed main(void)
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;i++)cin>>A[i];
	int *s=A;
	int tot=0,ans=0;
	for (int *e=A;e<=A+N;e++){
		tot+=*e;
		while(e>=s&&e-s>=K)tot-=*(s++);
		while(e>=s&&*s<=0)tot-=*(s++);
		if(tot<=0){tot=0;s=e+1;}
		ans=max(ans,tot);
	}
	cout<<ans<<'\n';
}
