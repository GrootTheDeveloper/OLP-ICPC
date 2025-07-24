#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1000006];
int f[5];

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("TASK.INP","r",stdin);
	//freopen("TASK.OUT","w",stdout);
	int n; cin >> n;
	int sum=0;
	for (int i=1;i<=n;i++) cin >> a[i],sum+=a[i];
	if (sum%4!=0) return cout << 0,0;
	int t1=sum/4,t2=t1*2,t3=t1*3;
	int cur=0;
	for (int i=1;i<=n-1;i++)
	{
		cur+=a[i];
		if (cur==t1) f[1]++;
		else if (cur==t2) f[2]+=f[1];
		else if (cur==t3) f[3]+=f[2];
	}
	cout << f[3];
	
	
	
}