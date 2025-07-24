#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
//#define int long long
struct point
{
	int x, y;
	point() : x(0), y(0) {};
	bool operator < (const point &other) const
	{
		return (x == other.x? y < other.y : x < other.x);
	}
}a[1000006];
struct node
{
	int val, id;
	node() : val(0), id(0) {};
	node(int a, int b) : val(a), id(b) {};
	bool operator < (const node &other) const
	{
		return (val == other.val? id < other.id : val < other.val);
	}
}b[1000006];
int bit[1000006];
int m, n;
void add(int &a, int b)
{
	a += b;
	if (a >= mode) a -= mode;
}
void update(int idx, int val)
{
	for (; idx <= n; idx += idx & -idx)
		add(bit[idx], val);
}
int get(int idx)
{
	int ans = 0;
	for (; idx; idx -= idx & -idx)
		add(ans, bit[idx]);
	return ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a + 1, a + n + 1);

	for (int i = 1; i <= n; i++)
		b[i] = node(a[i].y, i);
	sort(b + 1, b + n + 1);
	
	for (int i = 1; i <= n; i++)
		update(b[i].id, 1 + get(b[i].id - 1));

	cout << get(n);

}