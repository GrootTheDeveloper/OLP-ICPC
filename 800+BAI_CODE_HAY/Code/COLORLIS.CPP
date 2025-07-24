#include <bits/stdc++.h>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n; 
	vector<int> vec;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		int pos = lower_bound(vec.begin(), vec.end(), ai) - vec.begin();
		if (pos == (int)vec.size()) vec.push_back(ai);
		else vec[pos] = ai;
	}
	cout << vec.size() << '\n';
}