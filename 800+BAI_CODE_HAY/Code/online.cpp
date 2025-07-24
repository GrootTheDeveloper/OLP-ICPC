#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	int d = 0, res = 0;
	for (char c : s)
	{
		if (c == '1') res += ++d;
		else d = 0;
	}
	cout << res;
}