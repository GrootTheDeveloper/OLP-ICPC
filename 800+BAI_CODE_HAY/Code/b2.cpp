#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[1000005],n,p[1000005],cnt;

void init()
{
	p[1]=1;
	for (int i=2;i<=1e6;i++)
	{
		if (p[i]==0) for (int j=i;j<=1e6;j+=i) p[j]=i;
	}
}

string solve(int n)
{
	while (n!=1)
	{
		f[p[n]]++;
		if (f[p[n]]%2==1) cnt++;
		else cnt--;
		n/=p[n];
	}
	if (cnt) return "NE";
	else return "DA";
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("clucky.inp","r",stdin);
	freopen("clucky.out","w",stdout);
	init();
	int t,ai; cin >> t;
	while (t--)
	{
		cin >> ai;
		cout << solve(ai) << '\n';
	}

}
