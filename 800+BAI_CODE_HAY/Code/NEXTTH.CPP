#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[100005], b[100005];
bool cnt[100005];
multiset<int> List;

int nxt_val(int x)
{
	auto it = List.upper_bound(x);
	if (it == List.end())
		return -1;
	return *it;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
		cin >> a[i], cnt[a[i]] = true;

	for (int i = 1; i <= k; i++)
		b[i] = a[i];
	for (int i = 1; i <= n; i++)
		if (!cnt[i]) List.insert(i);

	int step = k;
	bool type = false;
	while (true)
	{
		if (step == k + 1) break;
		if (step == 0) return cout << -1, 0;
		int value = (type? nxt_val(b[step - 1]) : nxt_val(b[step]));
		if (value == -1)
		{ 
			List.insert(b[step]);
			--step, type = false;
		}
		else
		{
			List.insert(b[step]);
			b[step] = value;
			List.erase(value);
			++step, type = true;
		}
	}
	for (int i = 1; i <= k; i++)
		cout << b[i] << ' ';
	
}