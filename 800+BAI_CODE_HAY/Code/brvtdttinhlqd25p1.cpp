#include <bits/stdc++.h>
using namespace std;

int appear[10000007];
int divs[10000007];
bool prime[10000007];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("TOMMY.INP","r",stdin);
	freopen("TOMMY.OUT","w",stdout);
	int n; cin >> n;
	int lim = 0;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		appear[x]++;
		lim = max(lim, x);
	}

	for (int i = 2; i <= lim; i++)
	for (int j = i; j <= lim; j += i)
	{
		if (!prime[i]) divs[i] += appear[j];
		if (j != i) prime[j] = true;
	}

	for (int i = 1; i <= lim; i++)
		divs[i] += divs[i - 1];
	
	int q; cin >> q;
	while (q--)
	{
		int l, r; cin >> l >> r;
		if (l > lim) cout << 0;
		else cout << divs[min(r, lim)] - divs[l - 1];
		cout << '\n';
	}
}