#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,w;
long double a[1111],b[1111];


int calc()
{
	multiset <long double> s;
	for (int i=1;i<=n;i++)
	{
		long double ai=round((a[i]/b[i])*10000)/10000;
		s.insert(ai);
		auto it=s.lower_bound(ai);
		it++;
		if (it!=s.end()) s.erase(it);
	}
	return (int)s.size();
}

void sub()
{
	int res=0;
	for (int i=1;i<=n;i++)
	{
		swap(a[i],b[i]);
		res=max(res,calc());
		swap(a[i],b[i]);	
	}
	cout << res;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n >> w;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> b[i];
	}
	if (w==0) cout << calc();
	else sub();
}