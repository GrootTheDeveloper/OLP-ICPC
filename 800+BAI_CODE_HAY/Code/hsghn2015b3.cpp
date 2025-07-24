#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <string> v;
bool cmp(string s1, string s2)
{
	return s2+s1<s1+s2;
}

main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);
	freopen("cau3.inp","r",stdin);
	freopen("cau3.out","w",stdout);
	int n; cin >> n;
	int lim=(int)sqrt(n);
	for (int i=2;i<=lim;i++)
	{
		while (n%i==0)
		{
			v.push_back(to_string(i));
			n/=i;
		}
	}
	if (n!=1) v.push_back(to_string(n));
	sort(v.begin(),v.end(),cmp);
	for (string c : v) cout << c;
}