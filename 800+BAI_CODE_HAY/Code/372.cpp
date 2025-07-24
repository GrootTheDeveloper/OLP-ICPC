#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long val, u, last;
	bool operator < (const node &other) const
	{
		return val > other.val;
	}
};
long long dis[100005];
int a[100005];
vector<int> List[100005];
short mask[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, L, R, X, sta, en; cin >> n >> L >> R >> X >> sta >> en;
	vector<int> b;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(), end(b));
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i = 1; i <= n; i++)
	{
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		List[a[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		dis[i] = 1e15;
	priority_queue<node> q;
	q.push({0, sta, 0});
	dis[sta] = 0;

	while (q.size())
	{
		node top = q.top(); q.pop();
		long long u = top.u, distance = top.val, last = top.last;
		if (distance > dis[u]) continue;
		if (u - 1 != 0 && dis[u - 1] > distance + L)
		{
			dis[u - 1] = distance + L;
			q.push({dis[u - 1], u - 1, a[u]});
		} 
		if (u + 1 != n + 1 && dis[u + 1] > distance + R)
		{
			dis[u + 1] = distance + R;
			q.push({dis[u + 1], u + 1, a[u]});
		} 

		if (last != a[u] && mask[a[u]] < 2)
		{
			mask[a[u]]++;
			for (int &v : List[a[u]])
			if (v != u && dis[v] > distance + X)
			{
				dis[v] = distance + X;
				q.push({dis[v], v, a[u]});
			}
		}
	}

	cout << dis[en];

}