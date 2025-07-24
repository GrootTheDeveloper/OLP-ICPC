#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define x first
#define y second
ii a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("DT.INP","r",stdin);
	//freopen("DT.OUT","w",stdout);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	sort(a + 1, a + n + 1, [](ii a, ii b){ return a.x < b.x;});
	int res = 0, cnt = 0, d = 0;
	int last = -1e10, fir = -1e10;
	for (int i = 1; i <= n; i++)
	{
		if (a[i].x <= last)
		{
			cnt++;
			last = max(last, a[i].y);
		}else
		{
			fir = a[i].x;
			cnt = 1;
			last = a[i].y;
		}
		if (res < last - fir)
		{
			res = last - fir;
			d = cnt;
		}else if (res == last - fir) d = max(d, cnt);
		
	}
	cout << res << '\n' << d;

}