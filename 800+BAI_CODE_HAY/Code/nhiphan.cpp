#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[1000000],cnt[100005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,k; cin >> n >> k;
	string s; cin >> s;
	for (int i=0;i<n;i++) cnt[i]=(s.back()-'0'),s.pop_back();
	int x=0,mx=n-1;
	while (k!=1) x++,k/=2;
	for (int i=0;i<n;i++)
		if (cnt[i]) f[i]++,f[i+x]++,mx=max(mx,i+x);
	for (int i=0;i<=mx;i++)
	{
		s=s+to_string(f[i]%2);
		f[i+1]+=f[i]/2;
	}
	while (f[mx+1])
	{
		mx++;
		s+=to_string(f[mx]%2);
		f[mx+1]=f[mx]/2;
	}
	for (int i=mx;i>=0;i--) cout << s[i];


}