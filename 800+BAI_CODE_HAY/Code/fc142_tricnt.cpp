#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define len first
#define cnt second
const int mode = 1e9 + 7;
ii a[1111];
int v[100005], l[1005], pre[1003];
int n;
void sub1()
{
	int lim = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= a[i].cnt; j++)
			v[++lim] = a[i].len;
	}
	int ans = 0;
	for (int i = 1; i <= lim; i++)
		for (int j = i + 1; j <= lim; j++)
			for (int z = j + 1; z <= lim; z++)
				if (v[i] + v[j] > v[z] && v[i] + v[z] > v[j] && v[j] + v[z] > v[i]) ans++;
	cout << ans << ' ';
}

void sub2()
{
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i].cnt, l[i] = a[i].len;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			int x = (l[i] == l[j]? a[i].cnt * (a[i].cnt - 1) / 2 : a[i].cnt * a[j].cnt) % mode;
			int p = lower_bound(l + j, l + n + 1, l[i] + l[j]) - l - 1;
			ans = (ans + x * (pre[p] - pre[j])) % mode;

			if (i != j && l[j] * 2 > l[i])
			{
				int y = a[j].cnt * (a[j].cnt - 1) / 2;
				ans += y * a[i].cnt;
				ans %= mode;
			}
		}
	for (int i = 1; i <= n; i++)
	{
		int x = a[i].cnt;
		ans += x * (x - 1) * (x - 2) / 6;
		ans %= mode;
	}
	cout << ans;


}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].len >> a[i].cnt;
	//sub1();
	sub2();
}