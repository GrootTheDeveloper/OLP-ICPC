#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector <int> v;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		while (v.size()) 
		{
			if (a[v.back()] >= a[i]) v.pop_back();
			else break;
		}
		if (v.empty()) cout << 0 << ' '; 
		else cout << v.back() << ' ';
		v.push_back(i);
	}
}