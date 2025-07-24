#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve()
{
	string s; cin >> s;
	s+='+';
	int i=0,odd=0;
	while (i!=s.size())
	{
		bool check=false;
		while (s[i]!='+')
		{
			if (s[i+1]=='+' || s[i+1]=='*') 
			{
				if ((s[i]-'0')%2==0) check=true;
			}
			i++;
		}
		odd+=(!check);
		i++;
	}
	cout << odd%2 << '\n';
}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}