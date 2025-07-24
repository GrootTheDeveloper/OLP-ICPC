#include <bits/stdc++.h>
using namespace std;

int a[1000006];
int lim = 0;
void gen(int i, int s)
{
	a[++lim] = s;
	if (i > 10) return;
	for (int x = max(1, s % 10 + 1); x <= 9; x++)
		gen(i + 1, s * 10 + x);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	gen(1, 0);
	sort(a + 1, a + lim + 1);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int pos = upper_bound(a + 1, a + lim + 1, n) - a - 1;
		cout << a[pos] << '\n';
	}

}