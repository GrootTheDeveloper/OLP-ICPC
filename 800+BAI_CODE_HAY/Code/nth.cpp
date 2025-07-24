#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,n;

int calc()
{
	int lcm=a*b/__gcd(a,b);
	int l=1,r=(int)1e15;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (mid/a+mid/b-mid/lcm>=n) r=mid-1;
		else l=mid+1;
	}
	while (l/a+l/b-l/lcm<n) l++;
	while ((l-1)/a+(l-1)/b-(l-1)/lcm>=n) l--;
	return l;

}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> a >> b >> n;
		cout << calc() << '\n';
	}
}