#include <bits/stdc++.h>
using namespace std;
#define int long long 
int ai,d[4],c[4],cnt;
unordered_map <int,bool> f;
main()
{
	for (int i=1;i<=3;i++) for (int j=1;j<=3;j++) 
	{
		cin >> ai;
		d[i]+=ai;
		c[j]+=ai;
		cnt+=(f[ai]==false);
		f[ai]=true;
	} 
	if (cnt>1 && d[1]==d[2] && d[2]==d[3] && c[1]==c[2] && c[2]==c[3])
		cout << "YES";
	else
		cout << "NO";

}