#include <bits/stdc++.h>
using namespace std;
#define int long long 
string s;

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for (int n,b,ba,bab; t; t--)
	{
		b=0;ba=0;bab=0;
		cin >> n;
		cin >> s;
		for (char &c : s)
		{
			if (c == 'B') b++,bab+=ba;
			else if (c == 'A') ba+=b;
		}
		cout << bab << '\n';
	}

}