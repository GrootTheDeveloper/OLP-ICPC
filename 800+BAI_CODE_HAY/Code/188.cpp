#include <bits/stdc++.h>
using namespace std;

struct node
{
	int u, v, step;
	node (int a, int b, int c) : u(a), v(b), step(c){};
};

int x[4] = {0, 0, -1, 1}, y[4] = {1, -1, 0, 0};
int m, n;
int par[3000006], sz[3000006], lct[3];
char a[3000][3000];
int face(int i, int j)
{
	return n * (i - 1) + j;
}
void make_set(int n)
{
	for (int i = 1; i <= n; i++)
		par[i] = i, sz[i] = 1;
}
int Find(int v) {return (v == par[v]? v : par[v] = Find(par[v]));}
void Unite(int a, int b)
{
	a = Find(a), b = Find(b);
	if (a == b) return;
	if (sz[a] < sz[b]) 
		swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
}
void Join(int u, int v)
{
	for (int i = 0; i < 4; i++)
	if (a[u + x[i]][v + y[i]] == '.')
		Unite(face(u, v), face(u + x[i], v + y[i]));
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];
	queue<node> q;
	make_set(m * n);
	int cur_pos = 0;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
	if (a[i][j] == '.' || a[i][j] == 'L')
	{
		Join(i, j);
		q.push(node(i, j, 0));
		if (a[i][j] == 'L')
			lct[++cur_pos] = face(i, j), a[i][j] = '.';
	}	
	
	while (q.size())
	{
		node tmp = q.front(); q.pop();
		int u = tmp.u, v = tmp.v, step = tmp.step;
		for (int i = 0; i < 4; i++)
		{
			int nu = u + x[i], nv = v + y[i];
			if (a[nu][nv] == 'X')
				a[nu][nv] = '.', q.push(node(nu, nv, step + 1)), Join(nu, nv);
		}
		if (Find(lct[1]) == Find(lct[2]))
			return cout << step + 1, 0;		
	}	
}