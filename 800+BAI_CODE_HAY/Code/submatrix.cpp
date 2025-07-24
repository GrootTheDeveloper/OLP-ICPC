#include <bits/stdc++.h>
using namespace std;

int x1, x2, y1, y2, dif_num;
int a[333][333], cnt[90005], m, n, k;
void add(int &val){
	dif_num += (++cnt[val] == 1);
}
void del(int &val){
	dif_num -= (--cnt[val] == 0);
}

bool move_rigth(){
	for (int i = x1; i <= x2; i++)
		del(a[i][y1]), add(a[i][y2 + 1]);
	y1++, y2++;
	return (dif_num <= k);
}
bool move_left(){
	for (int i = x1; i <= x2; i++)
		del(a[i][y2]), add(a[i][y1 - 1]);
	y2--, y1--;
	return (dif_num <= k);
}
bool down(){
	for (int i = y1; i <= y2; i++)
		del(a[x1][i]), add(a[x2 + 1][i]);
	x1++, x2++;
	return (dif_num <= k);
}
void clear()
{
	for (int i = x1; i <= x2; i++)
	for (int j = y1; j <= y2; j++)
		del(a[i][j]);
}
bool check(int x)
{
	clear();
	for (int i = 1; i <= x; i++)
	for (int j = 1; j <= x; j++)
		add(a[i][j]);
	if (dif_num <= k) return true;
	x1 = 1, x2 = x, y1 = 1, y2 = x;
	for (int i = 1; i <= (m - x + 1); i++)
	{
		if (y1 == 1){
			for (int step = 1; step <= n - x; step++)
				if (move_rigth()) return true;
		} 
		else if (y2 == n){
			for (int step = 1; step <= n - x + 1; step++)
				if (move_left()) return true;
		}
		if (x2 < m) if (down()) return true;
	}
	return false;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];
	int ans = -1, l = 1, r = min(m, n);
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) 
			ans = mid, l = mid + 1;
		else
			r = mid - 1;
	}
	cout << ans;
}