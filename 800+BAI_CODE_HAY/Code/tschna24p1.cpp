#include <bits/stdc++.h>
using namespace std;
#define int long long

int l,res=(int)1e18,a,b;
int val[100];
void pt(int n)
{
	int lim=trunc(sqrt(n));
	for (int i=2;i<=lim;i++)
		while (n%i==0) val[++l]=i;
	if (n!=1)
		val[++l]=n;
}
void Try(int i)
{
	if (i>l) return res=min(res,a+b),void();
	a*=val[i];
	Try(i+1);
	a/=val[i];
	b*=val[i];
	Try(i+1);

}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int m,n; cin >> m >> n;
	if (n%m!=0) return cout << -1,0;
	a=m;b=m;
	n/=m;
	pt(n);
	Try(1);
	cout << res;


}