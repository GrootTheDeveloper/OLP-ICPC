#include <bits/stdc++.h>
using namespace std;
#define int long long 
int calc (int x) { return x * x * x - 2 * x + 5;}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for (int K; t; t--)
	{
		cin >> K;
		int l = 1, r = 3e6;
		while (l < r)
		{
			int mid = (l + r) / 2;
			if (calc(mid) >= K) r = mid - 1;
			else l = mid + 1;
		}		
		while (calc(l) < K) l++;
		while (calc(l - 1) >= K && l-1 > 0) l--;
		
		cout << ((calc(l) == K) ? l : -1) << '\n';
	}
}