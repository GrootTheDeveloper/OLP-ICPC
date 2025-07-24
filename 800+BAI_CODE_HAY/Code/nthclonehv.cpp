#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a,b,n,_lcm;

int lcm()
{
	return a*b/__gcd(a,b);
}
bool cou(int mid)
{
	return (mid/a + mid/b - mid/_lcm >= n);
}
int calc()
{
	int l=1,r=(int)1e15;
	_lcm=lcm();
	while (l<r)
	{
		int mid=(l+r)/2;
		if (cou(mid)) r = mid - 1;
		else l = mid + 1;
	}
	while (!cou(l)) l++;
	while (cou(l-1)) l--;
	return l;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> a >> b >> n;
		cout << calc() << '\n';
	}
}