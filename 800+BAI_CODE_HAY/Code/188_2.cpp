#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 2e5 + 2e4 + 31 + 01 + 2007;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
int inp[3], par[N], sz[N];
char a[1555][1555];
int n, m;
int tranf(int x, int y)
{
	return (x - 1) * n + y;
}
void make_set(int n)
{
	for (int i = 1; i <= n; i++)
		par[i] = i, sz[i] = 1;
}
int Find(int v) { return (v == par[v]? v : par[v] = Find(par[v]));}
void unite(int a, int b)
{
	a = Find(a); b = Find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
}
struct node
{
	int x, y, step;
	node (int a, int b, int c) : x(a), y(b), step(c) {};
};
void process(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (a[nx][ny] == '.' || a[nx][ny] == 'L')
			unite(tranf(x, y), tranf(nx, ny));
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];

	int cnt = 0;
	make_set(m * n);
	queue<node> q;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	{
		if (a[i][j] == 'L')
			inp[++cnt] = tranf(i, j);
		bool mask = false;
		if (a[i][j] == 'L' || a[i][j] == '.')
		{
			for (int e = 0; e < 4; e++)
			{
				if (a[i + dx[e]][j + dy[e]] == '.' || a[i + dx[e]][j + dy[e]] == 'L')
					unite(tranf(i,j), tranf(i + dx[e], j + dy[e]));
				if (a[i + dx[e]][j + dy[e]] == 'X')
					mask = true;
			}
		}
		if (mask) q.push(node(i, j, 0));
	}
	if (Find(inp[1]) == Find(inp[2])) return cout << 0, 0;
	while (q.size())
	{
		node top = q.front(); q.pop();
		int x = top.x, y = top.y, step = top.step;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (a[nx][ny] == 'X')
			{
				a[nx][ny] = '.';
				q.push(node(nx, ny, step + 1));
				process(nx, ny);
			}
		}
		if (Find(inp[1]) == Find(inp[2])) return cout << step + 1, 0;
	}
	
}