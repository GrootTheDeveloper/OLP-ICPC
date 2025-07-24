#include <bits/stdc++.h>
using namespace std;
#define int long long 
string s;
int f[2222][2222];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> s;
	s='#'+s;
	int n=s.size()-1;
	for (int i=1;i<=n;i++) f[i][i]=1;
	for (int l=2;l<=n;l++)
	for (int i=1;i<=n-l+1;i++)
	{
		int j=i+l-1;
		f[i][j]=max(f[i+1][j],f[i][j-1]);
		if (s[i]==s[j])
		{
			if (l==2) f[i][j]=2;
			else f[i][j]=f[i+1][j-1]+2;
		}
	}
	cout << f[1][n];
}