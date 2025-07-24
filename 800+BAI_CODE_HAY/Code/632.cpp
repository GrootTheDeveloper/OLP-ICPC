#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;

void lixi(int &a, int b)
{
	a += b;
	if (a >= mode) a -= mode;
}
int Chuc_mung_nam_moi(int a)
{
	int b = a + 1;
	if (b & 1) a /= 2;
	else b /= 2;
	return (a % mode) * (b % mode) % mode;
}
int Happy_new_year(int l, int r)
{
	return (Chuc_mung_nam_moi(r) - Chuc_mung_nam_moi(l - 1) + mode) % mode;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int nex = n / (n / i);
		lixi(ans, Chuc_mung_nam_moi(n / i) * Happy_new_year(i, nex) % mode);
		i = nex;
	}
	cout << ans;
}