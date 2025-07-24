#include <bits/stdc++.h>
using namespace std;

int n;
int x[1000006], y[1000006];
void sub1()
{
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
		ans += (x[i] == x[j] || y[i] == y[j]);
	cout << ans << ' ';
}

map <pair<int,int>, int> f;
vector<int> b;
int cntx[2000006], cnty[2000006];
void sub2()
{
	for (int i = 1; i <= n; i++)
		b.push_back(x[i]), b.push_back(y[i]);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		x[i] = lower_bound(b.begin(), b.end(), x[i]) - b.begin() + 1;
		y[i] = lower_bound(b.begin(), b.end(), y[i]) - b.begin() + 1;

		ans += cntx[x[i]]++;
		ans += cnty[y[i]]++;
		ans -= f[{x[i], y[i]}]++;
	}
	cout << ans;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("chick.inp","r",stdin);
	freopen("chick.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> x[i] >> y[i];

	if (n <= 500) sub1();
	else sub2();

}