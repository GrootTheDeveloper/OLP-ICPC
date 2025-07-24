#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define sz(v) (int)v.size()
const int N = 2e5 + 5;

int bit[N];
struct BIT
{
	int n;
	void reset()
	{
		n = N;
		memset(bit, 0, sizeof(bit));
	}

	void update(int idx, int val)
	{
		for (; idx <= n; idx += idx & -idx)
			bit[idx] += val;
	}
	int get(int idx)
	{
		int ans = 0;
		for (; idx; idx -= idx & -idx)
			ans += bit[idx];
		return ans;
	}
}Bit;

int a[100005], b[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i], b[i] = a[i];

	sort(b + 1, b + n + 1);
	int l = 1, r = n;
	int total = n * (n + 1) / 2;
	int ans;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		int s = n + 1;
		int Sum = 0;
		Bit.reset();
		for (int i = 1; i <= n; i++)
		{
			if (a[i] >= b[mid]) 
				++s, Sum++;
			else 
				--s;
			Sum += Bit.get(s);
			Bit.update(s, 1);
		}

		if (Sum * 2 >= total) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	cout << b[ans];
}
