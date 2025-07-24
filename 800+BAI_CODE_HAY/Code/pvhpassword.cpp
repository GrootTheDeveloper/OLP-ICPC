#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s; cin >> s;
	int k; cin >> k;
	int res=0;
	for (char c : s)
	{
		int delta=c-'a';
		if (k+delta<=25) res+=k+delta;
		else res+=(k+delta-1)%25;
	}
	cout << res;
}