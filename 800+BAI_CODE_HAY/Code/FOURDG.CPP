#include <bits/stdc++.h>
using namespace std;

int rot(int step, int pos)
{
	if (step == 0 && pos == 1) 
		return 0;
	return (pos & 1? rot(step - 1, pos / 2 + 1) : 1 ^ rot(step - 1, pos / 2));
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int x = k; x <= k + 3; x++)
		cout << rot(n, x);
}