#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector <int> ans;
	while (n != 1)
	{
		while (n % k != 0) n++, ans.push_back(2);
		n /= k;
		ans.push_back(1);
	}
	cout << ans.size() << '\n';
	for (int c : ans) cout << c << ' ';
}