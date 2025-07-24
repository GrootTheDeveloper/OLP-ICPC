#include <bits/stdc++.h>
using namespace std;
#define int long long 


main()
{
	freopen("MATKHAU.INP","r",stdin);
	freopen("MATKHAU.OUT","w",stdout);
	string s; getline(cin,s);
	int res=0;
	for (char c : s)
		if ('0'<=c && c<='9') res+=(c-'0')*(!((c-'0')&1));
	cout << res << s.size();
}