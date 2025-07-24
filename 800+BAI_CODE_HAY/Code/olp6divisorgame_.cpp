#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
int a[10000];
int opt(int n)
{
	int ans = 0;
	for (int i = 2; i < n; i++)
	if (n % i == 0) ans = max(ans, i + n / i);
	return ans;
}

ii ex(int n)
{
	int ans = 0;
	ii cur = {0, 0};
	for (int i = 2; i < n; i++)
	if (n % i == 0)
	{
		if (i + n / i > ans)
			ans = i + n / i, cur = {i, n / i};
	}
	return cur;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	priority_queue<ii> q;
	q.push({opt(n), n});
	int lim = 0;
	while (q.size())
	{
		ii top = q.top(); q.pop();
		a[++lim] = top.fi;
		ii tmp = ex(top.se);
		if (tmp.fi != 0)
			q.push({opt(tmp.fi), tmp.fi});
		if (tmp.se != 0)
			q.push({opt(tmp.se), tmp.se});
	}	
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= lim; i += 2)
		ans1+=a[i];
	for (int i = 2; i <= lim; i += 2)
		ans2 += a[i];
	cout << ans1 - ans2;
}