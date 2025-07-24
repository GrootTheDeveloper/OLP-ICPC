#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,a[111][111],cnt,mx,res;
int dx[8]={0,0,-1,1,-1,-1,1,1},
	dy[8]={1,-1,0,0,-1,1,1,-1};
void Try(int x, int y, int val)
{
	if (a[x][y]==val)
	{
		cnt++;
		res=max(res,cnt);
		a[x][y]=0;
		for (int i=0;i<8;i++)
			Try(x+dx[i],y+dy[i],val);

	}
}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("CAU4.INP","r",stdin);
	freopen("CAU4.OUT","w",stdout);
	cin >> m >> n;
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++) cin >> a[i][j];
	for (int i=1;i<=m;i++) for (int j=1;j<=n;j++)
		if (a[i][j]) cnt=0,Try(i,j,a[i][j]),mx+=(cnt>1);
	cout << mx << '\n' << res;
}