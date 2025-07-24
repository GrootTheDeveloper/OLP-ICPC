#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n, l;
int a[100005], b[100005];

bool check(int x)
{
	int cur = 0;
	for (int i = 1; i <= n; i++) if (a[i] < x)
	{
		cur += (x - a[i]) / b[i] + ((x - a[i]) % b[i] !=0);
		if (cur > l) return false;
	}
	return true;
}



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> l;
	for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
	int l = 1, r = 1e15;
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	while (!check(l)) l--;
	while (check(l + 1)) l++;
	cout << l;
}