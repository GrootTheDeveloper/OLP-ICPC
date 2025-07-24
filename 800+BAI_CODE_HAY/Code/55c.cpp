#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,k;
void sub1()
{
	vector <int> oo,v,tem;
	for (int i=0;i<=n;i++) v.push_back(i);
	while (v.size())
	{
		if (k==v.size()) break;
		for (int i=0;i<v.size();i++) 
		{
			if (i%k==0) cout << v[i] << ' ';
			else tem.push_back(v[i]);
		}
		v=(tem);
		tem=(oo);
	}
	for (int c : v) cout << c << ' ';
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("REMOVE.INP","r",stdin);
	freopen("REMOVE.OUT","w",stdout);
	cin >> n >> k;
	sub1();
}