#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[256];

main()
{
	string s; cin >> s;
	int res=0;
	for (char c : s)
	{
		f[(int)(c-'0')]++;
		res+=f[(int)(c-'0')]==2;
	}
	cout << res;
}