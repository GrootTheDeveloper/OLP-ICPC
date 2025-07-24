#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;

bool solve(string st)
{
	for (char c : s)
	{
		if (c=='+') st+=to_string(st.back()-'0'+1);
		if (c=='-') st+=to_string(st.back()-'0'-1);
		if (c=='=') st.push_back(st.back());
	}
	if (st.size()==s.size()+1) return cout << st,true; 
	return false;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> s;
	for (int i=1;i<=9;i++) 
		if (solve(to_string(i))) 
			return 0;
	cout << 0;
	
}