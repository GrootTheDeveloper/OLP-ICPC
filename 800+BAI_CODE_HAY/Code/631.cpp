#include <bits/stdc++.h>
using namespace std;
#define int long long 

int calc(int n)
{
	int ans = 0;
	for (int i = 1; i * i <= n; i++)
	{
		int Fi = i * i, Ed = min((i + 1) * (i + 1) - 1, n);
		ans += i * (Ed - Fi + 1);
	}
	return ans;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int l, r; cin >> l >> r;
	cout << calc(r) - calc(l - 1);
}