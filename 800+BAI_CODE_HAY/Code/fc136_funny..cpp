#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <int> d[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int x = 0;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		x ^= ai;
		cout << x  << ' ';
	}
}