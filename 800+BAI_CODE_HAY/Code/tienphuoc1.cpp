#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <int> v;

signed main()
{
	int n; cin >> n;
	v.push_back(0);
	for (int i=1;i<=1000;i++)
	{
		v.push_back((v.back()/i+1)*i);
		int k=i-1;
		while (k--)
			v.push_back(v.back()+i);
	}
	cout << v[n] << '\n';
	
	int ans=1,idx=1;
	while (n)
	{
		if (n>idx)
		{
			n-=idx;
			ans=ans+idx*(idx-1);
			idx++;
			ans=(ans/idx+1)*idx;
		}
		else 
		{
			ans=ans+idx*(n-1);
			n=0;
		}
	}
	cout << ans;
}