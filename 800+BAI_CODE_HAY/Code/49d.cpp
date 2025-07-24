#include <bits/stdc++.h>
using namespace std;
#define int long long 
int l,r;

int resum(int n)
{
	int res=0;
	for (int i=1;i<=n;i++) res+=n/i;
	return res;
}

void sub()
{
	int res=0;
	for (int i=l;i<=r;i++) res+=resum(i);
	cout << res;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("RANGE.INP","r",stdin);
	//freopen("RANGE.OUT","w",stdout);
	cin >> l >> r;
	//if (l==r && r<=1e7) cout << resum(l);
	//else sub();
	for (int i=l;i<=r;i++) cout << resum(i) << endl;
}