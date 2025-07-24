#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	int n; cin >> n;
	if (n == 0) return cout << 0, 0;
	if (n == 1) return cout << 1, 0;
	vector<int> v;
	for (int i = 9; i >= 2; i--)
	{
		while (n % i == 0)
			n /= i, v.push_back(i);
	}
	if (n != 1) return cout << -1, 0;
	reverse(begin(v), end(v));
	for (int c : v) 
		if (c != 0) cout << c;
}