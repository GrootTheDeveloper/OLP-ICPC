#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[4][1000];
void Try(int x, int y)
{
	if (a[x][y]==0) return;
	a[x][y]=0;
	if (x==1) Try(x+1,y),Try(x,y+1);
	else if(x==2) Try(x,y+1),Try(x-1,y);
}

void solve()
{
	memset(a,0,sizeof(a));
	int n; cin >> n;
	string s;
	cin >> s;
	for (int i=1;i<=n;i++)
		a[1][i]=(s[i-1]=='*');
	cin >> s;
	for (int i=1;i<=n;i++)  
		a[2][i]=(s[i-1]=='*');

	int cnt=0;
	for (int i=1;i<=2;i++)
		for (int j=1;j<=n;j++)  
			if (a[i][j]==1) cnt++,Try(i,j);
	cout << ( cnt==1? "YES":"NO") << '\n';

}
main()
{
	int t; cin >> t;
	while (t--) solve();
}