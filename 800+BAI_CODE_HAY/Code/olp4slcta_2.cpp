#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int f[5555];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	string s; cin >> s;
	s='#'+s;
	f[0]=1;
	for (int i=1;i<=n;i++)
	{
		int cnt1=0,cnt0=0;
		for (int j=i;j>=1;j--)
		{
			cnt1+=(s[j]=='1');
			cnt0+=(s[j]=='0');
			if (abs(cnt0-cnt1)<=k) f[i]=(f[i]+f[j-1])%mode;
		}
	}
	cout << f[n];
}