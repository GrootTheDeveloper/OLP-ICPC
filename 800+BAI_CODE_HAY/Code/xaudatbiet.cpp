#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;
int d[100005], pre[50][100005], a[50];
void add(int &a, int b)
{
	a += b;
	if (a >= mode) a -= mode;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	set<int> S;
	for (char c : s)
		if (S.find((int)c) == S.end()) S.insert((int)c);

	int lim = 0;
	for (int c : S)
		a[++lim] = c;

	s = " " + s;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= lim; j++)
			pre[j][i] = pre[j][i - 1] + ((int)s[i] == a[j]);
		int x = 0;
		for (int j = i - lim; j >= 0; j -= lim)
		{
			++x;
			
			int cnt = 0;
			for (int z = 1; z <= lim; z++)
				cnt += (pre[z][i] - pre[z][j] == x);
			
			if (cnt == lim)
			{
				add(ans, 1 + d[j]);
				d[i] = 1 + d[j];
				break;
			}
		}
	}
	cout << ans;
}