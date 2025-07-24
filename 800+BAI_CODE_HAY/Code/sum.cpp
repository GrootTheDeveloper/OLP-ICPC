#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> v;
void init()
{
	for (int i=1;i<9;i++)
	{
		int k=1,val=0;
		while (k--) val=val*10+i,v.push_back(val);
	}
}

signed main()
{
	int n; cin >> n;
	init();
	sort(v.begin(),v.end());
	for (int i=0;i<v.size();i++)
	{
		if (v[i]%n==0) return cout << v[i]/n,0;
	}
	cout << -1;
	return 0;
}