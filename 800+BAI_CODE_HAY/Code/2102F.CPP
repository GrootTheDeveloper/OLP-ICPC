#include <bits/stdc++.h>
using namespace std;

int zero;
int a[100005];
void add(int &val) { zero += (val == 0);}
void del(int &val) { zero -= (val == 0);}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int l = 1;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		add(a[i]);
		while (zero > k)
			del(a[l++]);
		ans = max(ans, i - l + 1);
	}
	cout << ans;
}