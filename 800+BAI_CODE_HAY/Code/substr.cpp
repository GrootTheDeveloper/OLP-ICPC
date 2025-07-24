#include <bits/stdc++.h>
using namespace std;
#define int long long 
string s1,s2;
int f[2001][2001];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> s1 >> s2;
	s1='#'+s1;
	s2='#'+s2;
	int m=(int)s1.size()-1,n=(int)s2.size()-1;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++)
		if (s1[i]==s2[j]) f[i][j]=f[i-1][j-1]+1;
		else f[i][j]=max(f[i-1][j],f[i][j-1]);
	cout << f[m][n];
}