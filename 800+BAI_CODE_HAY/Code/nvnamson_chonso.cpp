#include <bits/stdc++.h>
using namespace std;
#define int long long 
unordered_map <int, int> f;
int a[50];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> m;
	int mid = (n / 2);

	int mask = (1 << mid);
	for (int msk = 1; msk <= mask; msk++)
	{
		int sum = 0;
		for (int i = 0; i < mid; i++)
			if (msk & 1 << i) sum += a[i + 1];
		f[sum] = msk;
	}

	mask = (1 << (n - mid));
	int lim = n - mid;
	for (int msk = 1; msk <= mask; msk++)
	{
		int sum = 0;
		for (int i = 0; i < lim; i++)
			if (msk & 1 << i) sum += a[mid + i + 1];
		if (f.find(m - sum) != f.end())
		{
			int msk1 = f[m - sum];
			int msk2 = msk;
			for (int i = 0; i < mid; i++)
				if (msk1 & 1 << i) cout << 1; else cout << 0;
			for (int i = 0; i < lim; i++)
				if (msk2 & 1 << i) cout << 1; else cout << 0;
			return 0;			
		}
	}

}