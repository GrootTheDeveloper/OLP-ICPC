#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
const int inf = 1e9;

int d[1000006];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k; cin >> k;
	fill(d, d + k, inf);
	priority_queue <ii, vector<ii>, greater<ii>> q;
	for (int i = 1; i <= 9; i++)
	{
		int v = i % k;
		if (d[v] > i)
		{
			d[v] = i;
			q.push({d[v], v});
		}
	}

	while (q.size())
	{
		ii top = q.top(); q.pop();
		int u = top.se, w = top.fi;
		if (d[u] < w) continue;

		for (int wi = 0; wi <= 9; wi++)
		{
			int v = (u * 10 + wi) % k;
			if (d[v] > d[u] + wi)
			{
				d[v] = d[u] + wi;
				q.push({d[v], v});
			}
		}
	}
	cout << d[0];

}