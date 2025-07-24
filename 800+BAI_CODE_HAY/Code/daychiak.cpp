#include <bits/stdc++.h>
using namespace std;
#define int long long 

int f[100005],a[100005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("TASK.INP","r",stdin);
	//freopen("TASK.OUT","w",stdout);
	int n,k; cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i],a[i]%=k;
	int sum=0,res=0;
	for (int i=1;i<=n;i++)
	{
		sum+=a[i];
		if (sum%k==0) res=i;
		if (f[sum%k]==0) f[sum%k]=i;
		else res=max(res,i-f[sum%k]); 
	}
	cout << res;
	
}