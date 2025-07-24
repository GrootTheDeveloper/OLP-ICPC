#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[3000];

main()
{
	string s; getline(cin,s);
	int res=0;
	for (char c : s)
	{
		
			f[(int)c]++;
			res+=(f[(int)c]==2);
	}
	cout << res;
}