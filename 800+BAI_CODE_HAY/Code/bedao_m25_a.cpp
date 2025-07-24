#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;

int a[1000005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n; 
	int odd = 0, even = 0, cnt_even = 0, cnt_odd = 0;	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] & 1) odd += a[i], cnt_odd++;
		else even += a[i], cnt_even++;
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] & 1)
		{
			res = (res + a[i] * cnt_even + even) % mode;
			cnt_odd--;
			odd -= a[i];
		}
		else
		{
			res = (res + a[i] * cnt_odd + odd) % mode;
			cnt_even--;
			even -= a[i];
		}
	}
	cout << res;

}