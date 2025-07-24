#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	multiset <int> s1, s2;
	for (int i = 1; i <= n; i++)
	{
		s1.insert(a[i]);
		auto it = s1.lower_bound(a[i]);
		it++;
		if (it != s1.end()) s1.erase(it);
	}
	for (int i = n; i >= 1; i--)
	{
		s2.insert(a[i]);
		auto it = s2.lower_bound(a[i]);
		it++;
		if (it != s2.end()) s2.erase(it);
	}
	cout << min(n - s1.size(), n - s2.size());
}