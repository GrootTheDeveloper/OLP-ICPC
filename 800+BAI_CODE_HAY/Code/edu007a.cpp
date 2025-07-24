#include <bits/stdc++.h>
using namespace std;
#define int long long 

int on[10000002];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("CDIV.INP","r",stdin);
	freopen("CDIV.OUT","w",stdout);
	int n; cin >> n;
	int lim=0,ai;
	for (int i=1;i<=n;i++) cin >> ai,on[ai]++,lim=max(lim,ai);
	int res=1;
	for (int i=lim;i>=2;i--)
	{
		int cnt=0;
		for (int j=i;j<=lim;j+=i) 
		{
			cnt+=on[j];
			if (cnt>1) break;
		}
		
		if (cnt>1) 
		{
			res=i;
			break;
		}
	}
	cout << res;
}