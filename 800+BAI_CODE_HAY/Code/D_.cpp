#include <bits/stdc++.h>
using namespace std;

int isCnt[1000006];
int cnt_div[1000006];

void sie()
{
	for (int i = 1; i <= 1e6; i++)
	for (int j = i; j <= 1e6; j += i)
		cnt_div[i] += isCnt[j];
	for (int i = 1; i <= 1e6; i++)
		cnt_div[i] += cnt_div[i - 1];
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		isCnt[ai]++;
	}
	sie();
	int q; cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r;
		cout << cnt_div[r] - cnt_div[l - 1] << '\n';
	}
}