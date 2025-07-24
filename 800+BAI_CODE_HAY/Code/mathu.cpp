#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int,char> f;
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s;getline(cin,s);
	for (int i=1,c='a';i<=26 ;i++)
	{
		f[i]=c;
		c++;
	}
	for (int k=1;k<=25;k++)
	{
		for (char c : s)
		{
			if (c=='-' || c==' ') cout << ' ';
			else
			{
				int pos=c-'a'-1+k;
				if (pos>26) pos-=26; 
				cout << f[pos];
			}
		}
		cout << '\n';
	}
}