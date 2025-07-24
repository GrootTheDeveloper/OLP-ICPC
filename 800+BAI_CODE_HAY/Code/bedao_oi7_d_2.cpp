#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first 
#define se second 

int par[1000005], sz[1000005], a[1000005], b[1000005];
long long low;
int n;
long long  ans, s, cnt, p;
int mark[100005];

long long sum(int n)
{
	return n * (n + 1) / 2;
}

void Remove(int x)
{
	if (x >= low)
	{
		cnt--;
		ans -= sum(x - low + 1);
		s -= x - low + 1;
	}
	mark[x]--;
}
void tag(int x)
{
	if (x >= low)
	{
		cnt++;
		ans += sum(x - low + 1);
		s += x - low + 1;
	}
	mark[x]++;
}

void add(int v)
{
	par[v] = v;
	sz[v] = 1;
	tag(sz[v]);
}
int Find(int v)
{
	return (v == par[v]? v : par[v] = Find(par[v]));
}
void Unite(int a, int b)
{
	a = Find(a), b = Find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) swap(a, b);
	Remove(sz[a]);
	Remove(sz[b]);
	sz[a] += sz[b];
	par[b] = a;
	tag(sz[a]);
}

void del(int x)
{
	ans -= s;
	s -= cnt;
	cnt -= mark[x];
	mark[x] = 0;
}

void sub1()
{
	int lim = a[b[1]];
	int l = 1;
	long long res = 0;
	for (int x = lim; x >= 1; x--)
	{
		int newlow = (p - 1) / x + 1;
		if (newlow > n) break;
		if (low)
		{
			for (int i = low; i < newlow; i++)
				del(i);
		}
		low = newlow;
		while (a[b[l]] >= x && l <= n)
		{
			add(b[l]);
			if (par[b[l] + 1] != 0) Unite(b[l], b[l] + 1);
			if (par[b[l] - 1] != 0) Unite(b[l], b[l] - 1);
			l++;	
		}
		res += ans;
	}
	cout << res;
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); 
	freopen("CHART.INP","r",stdin);
	freopen("CHART.OUT","w",stdout);
	cin >> n >> p;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	iota(b + 1, b + n + 1, 1);
	sort(b + 1, b + n + 1, [](int x, int y)
	{
		return a[x] > a[y];
	});
	sub1();
	//cout << '\n' << clock() / (double)1000;
}