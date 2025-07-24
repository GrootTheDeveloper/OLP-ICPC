#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int> 
#define x first
#define y second

bool visited[2002][2002];
int d[2002][2002];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int c, s;
int l1, l2;
ii g[10004];


void inp()
{
	cin >> c >> s;
	for (int i = 1; i <= c; i++)
	{
		int x,y; cin >> x >> y;
		g[i] = {x,y};
		if (x < 0) l1 = min(l1,x);
		if (y < 0) l2 = min(l2,y);
	}
	l1 *= -1;
	l2 *= -1;
	l1 = max(l1,s);
	l2 = max(l2,s);
	for (int i = 1; i <= c; i++)
		visited[g[i].x + l1][g[i].y + l2] = true;
	
}
void solve()
{
	if (s > 1e3) return;
	if (visited[l1][l2]) return cout << 0, void();
	queue <ii> q;
	q.push({l1,l2});
	visited[l1][l2] = true;
	int res = 0;
	while (q.size())
	{
		ii top = q.front(); q.pop();
		if (d[top.x][top.y] == s) continue;
		for (int i = 0; i < 4; i++)
		{
			if (!visited[top.x + dx[i]][top.y + dy[i]])
			{
				res ++;
				visited[top.x + dx[i]][top.y + dy[i]] = true;
				q.push({top.x + dx[i], top.y + dy[i]});
				d[top.x + dx[i]][top.y + dy[i]] = d[top.x][top.y] + 1;
			}
		}
	}
	cout << res + 1;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	inp();
	solve();
}