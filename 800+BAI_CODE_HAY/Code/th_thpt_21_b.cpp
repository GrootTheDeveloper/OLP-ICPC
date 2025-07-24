#include <bits/stdc++.h>
using namespace std;
#define int long long 
string a[1000006],b[1000006];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("bai2.inp","r",stdin);
	freopen("bai2.out","w",stdout);
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	int n=1;
	for (char c: s1)
		if (c!=' ')
			{
				if (c!=a[n].back()) a[n]+=c;
			}
		else n++;
	int j=1;
	for (char c:s2) if (c!=' ')
			{
				if (c!=b[j].back()) b[j]+=c;
			}
		else j++;
	int res=0;
	for (int i=1;i<=n;i++) res+=(a[i].size()==b[i].size());
	cout << res;
}