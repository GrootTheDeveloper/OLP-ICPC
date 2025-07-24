#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

bool isCycle[N];
int par[N], min_value[N], sz[N], value[N], x[N], y[N], q[N];
long long curent_ans, sum_value[N], contribute[N], ans[N];


void make_set(int n)
{
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;	
		sz[i] = 1;
		min_value[i] = sum_value[i] = value[i];
		isCycle[i] = false;
	}
}
int Find(int v) {return (v == par[v]? v : par[v] = Find(par[v]));}

void Unite(int a, int b)
{
	a = Find(a), b = Find(b);
	if (a == b)
	{
		if (isCycle[a] == false)
		{
			isCycle[a] = true;
			contribute[a] = sum_value[a];
			curent_ans += min_value[a];
		}
		return;
	}
	if (sz[a] < sz[b]) swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
	sum_value[a] += sum_value[b];
	min_value[a] = min(min_value[a], min_value[b]);

	curent_ans -= contribute[a] + contribute[b];

	isCycle[a] = (isCycle[a] || isCycle[b]);
	contribute[a] = (isCycle[a]? sum_value[a] : sum_value[a] - min_value[a]);
	curent_ans += contribute[a];

}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> value[i];
	for (int i = 1; i <= k; i++)
		cin >> x[i] >> y[i];

	for (int i = 1; i <= k; i++)
		cin >> q[i];

	make_set(n);
	for (int i = k; i >= 1; i--)
	{
		ans[i] = curent_ans;
		Unite(x[q[i]], y[q[i]]);
	}
	for (int i = 1; i <= k; i++)
		cout << ans[i] << '\n';	

}