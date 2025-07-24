#include <bits/stdc++.h>
using namespace std;
#define int long long 

unordered_map <int,char> f;
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	char c='A';
	for (int i=1;i<=25;i++)
	{
		f[i]=c;
		c++;
	}
	string s; cin >> s;
	s.push_back('-');
	string st="";
	for (int k=1;k<=24;k++)
	{
		for (char c : s)
		{	
			if (c!='-')
				st.push_back(c);
			else
			{
				int pos=stoll(st);
				st="";
				pos+=k;
				if (pos>25) pos-=25;
				cout << f[pos];
			}
		}
		cout << '\n';
	}

}