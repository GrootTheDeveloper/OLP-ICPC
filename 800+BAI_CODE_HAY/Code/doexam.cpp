#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool f[30];
int a[30],n,k,res;
void check()
{
	int cnt=0,s=0;
	for (int i=1;i<=n;i++) 
		if (f[i] && cnt<k) s+=a[i],cnt++; 
	res=max(res,s);
}
void Try(int i)
{
	if (i==n+1) return check(),void();
	if (f[i-1]==0) f[i]=1,Try(i+1);
	else 
	{
		f[i]=1;Try(i+1);
		f[i]=0;Try(i+1);
	}
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0); 
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	f[0]=1;
	Try(1);
	cout << res;
}