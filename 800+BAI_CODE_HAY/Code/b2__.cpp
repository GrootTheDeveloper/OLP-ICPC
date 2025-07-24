#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s; s = s + "#";
	set <int> lis;
	string st;
	for (char c : s)
	{
		if (c >= '0' && c <= '9') st.push_back(c);
		else
		{
			if (st.size()) lis.insert(stoll(st));
			st = "";
		}
	}
	cout << lis.size();

}