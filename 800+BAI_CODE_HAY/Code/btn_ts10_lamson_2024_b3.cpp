#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,a,b;

int lcm(int a, int b) {return a*b/__gcd(a,b);}
int calc(int n)
{
	return n/a+n/b-n/lcm(a,b);
}
void solve()
{
	cin >> a >> b >> n;
	int l=1,r=(int)1e15;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (calc(mid)>=n) r=mid-1;
		else l=mid+1;
	}
	while (calc(l)<n) l++;
	while (calc(l-1)>=n) l--;
	cout << l << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--)

		solve();
}