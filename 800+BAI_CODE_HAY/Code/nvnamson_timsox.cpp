#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,x; cin >> n >> x;
	int l = n / 3 * 2, r = n - n/3 + 1;
	if (x >= r)
	{
		if ((n - x + 1) & 1) return cout << "C",0;
		else return cout << "A",0;
	}
	if (x <= l)
	{
		int k = x/2 + (x&1);
		if (k & 1)
		{
			if (x&1) return cout << "A",0;
			else return cout << "B",0;
		}
		else
		{
			//BC
			if (x&1) return cout << "B",0;
			else return cout << "C",0;
		}

	}
	cout << "B";
}