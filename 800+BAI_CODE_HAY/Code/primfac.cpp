#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector <int> v;
unordered_map <int,int> f;
main()
{
	int n; cin >> n;
	int lim=(int)sqrt(n);
	for (int i=2;i<=lim;i++)
	{
		if (n%i==0)
		{
			v.push_back(i);
			while (n%i==0) f[i]++,n/=i;
		}
	}
	if (n!=1) f[n]++,v.push_back(n);
	cout << v.size() << '\n';
	for (int c : v) cout << c << ' ' << f[c] << '\n';
}