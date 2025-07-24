#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s; cin >> s;
	string st="virus";
	int res=0;
	for (int i=0;i<=(int)s.size()-5;i++)
	{
		bool check=false;
		if (s[i]=='v')
		{
			check=true;
			for (int j=i;j<=i+4;j++)
				if (s[j]!=st[j-i]) check=false;
		}
		res+=check; 
	}
	cout << res;
}