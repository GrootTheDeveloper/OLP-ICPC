#include <bits/stdc++.h>
using namespace std;
#define int long long

char a[1005][1005];
string s;
int m,n;
void Try(int x, int y)
{	
	if (a[x][y]=='.')
	{
		a[x][y]='#';
		Try(x+1,y);Try(x-1,y);
		Try(x,y+1);Try(x,y-1);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> m >> n;
	for (int i=1;i<=m;i++)
	{
		cin >> s;
		for (int j=1;j<=n;j++)
			a[i][j]=s[j-1];
	}
	int res=0;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++)
			if (a[i][j]=='.') res++,Try(i,j);
	cout << res;
}