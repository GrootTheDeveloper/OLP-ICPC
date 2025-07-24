#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool prime[32009];
vector <int> vi;
void sie()
{
	int lim=32005;
	for (int i=2;i*i<=lim;i++)
		if (!prime[i]) for (int j=i*i;j<=lim;j+=i) prime[j]=true;
	for (int i=2;i<=lim;i++) if (!prime[i]) vi.push_back(i);
}
bool check(int n)
{
	for (int c : vi)
	{
		if (n%(c*c)==0) return false;
		if (n%c==0) n/=c;
	}
	return true;
}
void solve(int x)
{
	if (x==1) return cout << 3 << '\n',void();
	int n=round(sqrt(x));
	int l=n,r=n;
	while (l>0)
	{
		if (check(l)) break;
		l--;
	}
	while (r<1e9) 
	{
		if (check(r)) break;
		r++;
	}
	int res=(int)1e18;
	if (l!=0) res=min(res,abs(l*l-x));
	if (r!=1e9) res=min(res,abs(r*r-x));
	cout << res << '\n';
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	sie();
	int t,x; cin >> t;
	while (t--)
	{
		cin >> x; solve(x);
	}
}