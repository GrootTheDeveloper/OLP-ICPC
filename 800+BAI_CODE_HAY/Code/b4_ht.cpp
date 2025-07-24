#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
int cnt[4], color[4];
int cnt_color;
ii a[1000005];

void add(int id)
{
	cnt_color += (++color[a[id].se] == 1);
}
void del(int id)
{
	cnt_color -= (--color[a[id].se] == 0);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].fi >> a[i].se, cnt[a[i].se]++;
	if (cnt[1] == 0 || cnt[2] == 0 || cnt[3] == 0) return cout << -1, 0;
	sort(a + 1, a + n + 1);
	int ans = a[n].fi - a[1].fi;
	int sta = 1;
	for (int i = 1; i <= n; i++)
	{
		add(i);
		while (cnt_color == 3)
		{
			ans = min(ans, a[i].fi - a[sta].fi);
			del(sta++);
		}
	}
	cout << ans;
}