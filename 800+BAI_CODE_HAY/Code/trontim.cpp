#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[10000];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int m,n; cin >> m >> n;
	string s;
	for (int i=1;i<=m;i++)
	{
		cin >> s;
		for (int j=0;j<n;j++)
		{
			f[j+1]+=(s[j]=='O');
		}
	}
	for (int i=1;i<=n;i++) cout << f[i] << ' ';
}