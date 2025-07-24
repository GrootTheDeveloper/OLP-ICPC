#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int> 
#define F first
#define S second

priority_queue <ii, vector<ii>, greater<ii>> q1;
priority_queue <ii> q2;

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("thidau.inp","r",stdin);
	freopen("thidau.out","w",stdout);
	int n; cin >> n;
	int s1 = 0, s2 = 0;
	for (int i = 1; i <= n; i++)
	{
		int u, v; cin >> u >> v;
		
		if (i&1) q2.push({u, v}), s2 += v;
		else q1.push({u, v}), s1 += v;
		
		if (i > 1)
		{
			while (q1.top().F < q2.top().F)
			{
				auto top1 = q1.top(); q1.pop();
				auto top2 = q2.top(); q2.pop();
				s1 = s1 + top2.S - top1.S;
				s2 = s2 + top1.S - top2.S;
				q1.push(top2);
				q2.push(top1);
			}
		}
		cout << abs(s1 - s2) << '\n';
	}
}