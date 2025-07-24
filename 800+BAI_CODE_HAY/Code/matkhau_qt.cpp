#include <bits/stdc++.h>
using namespace std;
#define int long long 
string s,st;

bool check(string ss)
{
	string tes=ss;
	while (tes.size()<s.size()) tes+=ss;
	return tes==s;
}
int f[256];
void solve(string st)
{
	int res=0;
	for (char c : st)
	{
		f[c-'a']++;
		res=max(res,f[c-'a']);
	}
	cout << res;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> s;
	int n=(int)s.size();
	for (char c : s)
	{
		st.push_back(c);
		if (n%(int)st.size()==0)
		{
			if (check(st)) {solve(st);break;}
		}
	}
}