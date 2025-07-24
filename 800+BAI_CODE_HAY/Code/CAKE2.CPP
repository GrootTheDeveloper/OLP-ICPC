#include <bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = 0, value, weight = 0;
	while (cin >> value)
	{
		++n;
		weight += value;
	}
	cout << weight - n + 1;
}