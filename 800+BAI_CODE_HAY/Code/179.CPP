#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
const int INF = 1e9;
int d[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int k; cin >> k;

	for (int i = 0; i < k; i++)
		d[i] = INF;

	priority_queue<ii, vector<ii>, greater<ii>> q;
	for (int i = 1; i <= min(9, k - 1); i++)
	{
		d[i] = i;
		q.push({i, i});
	}

	while (q.size())
	{
		ii top = q.top(); q.pop();
		int u = top.se, cur_sum = top.fi;
		if (cur_sum > d[u]) continue;
		for (int i = 0; i <= 9; i++)
		{
			int v = (u * 10 + i) % k;
			if (d[v] > cur_sum + i)
				d[v] = cur_sum + i, q.push({d[v], v});
		}
	}
	cout << d[0];
}