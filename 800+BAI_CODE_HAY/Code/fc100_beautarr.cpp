#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[500005], cnt[500005];
int exist;

void add(int val) { exist += (++cnt[val] == 3);}
void del(int val) { exist -= (--cnt[val] == 2);}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int l = 1;
	int ans = 0;
	for (int r = 1; r <= n; r++)
	{
		add(a[r]);
		while (exist) del(a[l++]);
		ans += (r - l + 1);
	}
	cout << ans;
}