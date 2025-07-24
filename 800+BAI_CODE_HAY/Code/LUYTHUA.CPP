#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second

int Sqrt(int n)
{
	int ans = sqrt(n);
	while (ans * ans > n)
		--ans;
	while ((ans + 1) * (ans + 1) <= n)
		++ans;
	return ans;
}

int calc_num_acp(int l, int r)
{
	if (l > r) return 0;
	r = Sqrt(r);
	int tmp = Sqrt(l);
	if (tmp * tmp == l) tmp--;
	return r - tmp;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b, k; cin >> a >> b >> k;
	int ans = 0;
	for (int y = 1; y <= 1e6; y++)
	{
		int tmp = y * y * y;
		if (tmp < a || tmp > b) continue;
		int case_val1 = tmp + k;
		int case_val2 = tmp - k;
		ans += calc_num_acp(max(a, case_val2), min(b, case_val1));
	}
	cout << ans;
}