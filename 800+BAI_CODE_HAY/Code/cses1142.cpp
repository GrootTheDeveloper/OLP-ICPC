#include <bits/stdc++.h>
using namespace std;
#define int long long 

int lef[200005],rig[200005],a[200005];

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];

	lef[1]=1;
	for (int i=2;i<=n;i++)
	{
		int pos=i-1;
		while (a[pos]>=a[i]) 
		{
			pos=lef[pos];
			if (pos==1) break;
			if (lef[pos]==pos && a[pos]>=a[i ]) pos--;
		}
		if (a[pos]<a[i]) lef[i]=pos+1;
		else lef[i]=pos;
		
	}

	rig[n]=n;
	for (int i=n-1;i>=1;i--)
	{
		int pos=i+1;
		while (a[pos]>=a[i]) 
		{
			pos=rig[pos];
			if (pos==n) break;
			if (pos==rig[pos] && a[pos]>=a[i]) pos++;
		}
		rig[i]=pos;
		if (a[pos]<a[i]) rig[i]--;
		
	}
	int res=0;
	for (int i=1;i<=n;i++) res=max(res,a[i]*(rig[i]-lef[i]+1)); 
	cout << res;
}