#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt[2002];
bool check[2002][2002];
bitset <2001> d[2001];
bitset <2001> temp;
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i = 1,x,y; i <= m; i++)	
	{
		cin >> x >> y;
		if (x > y) swap(x,y);
		cnt[x] ++;
		cnt[y] ++;
		check[x][y] = true;
		d[x].set(y);
		d[y].set(x);
	}
	//for (int i = 1; i <= n; i++) cout << d[i] << '\n';
	int res = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (!check[i][j])
			{
				temp = (d[i] & d[j]);
				res += (n - 2) - cnt[i] - cnt[j] + temp.count();
			}
	cout << res/3;
}