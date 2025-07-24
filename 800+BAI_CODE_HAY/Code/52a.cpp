#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a,b,n;

bool dq(int k)
{
	if (((k-a)%n==0 && k>=a) || ((k/a)%n==0 && k>=a) ) return 1;
	if (k<a) return 0;
	bool x,y;
	if (k%n==0 && n!=1) x=dq(k/n);
	if (x)  return 1;
	else y=dq(k-n);
	return x||y; 
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("TRANSFORM.inp","r",stdin);
	freopen("TRANSFORM.out","w",stdout);

	int t; cin >> t;
	while (t--)
	{
		cin >> a >> b >> n;
		bool res=dq(b);
		cout << (res? "Yes":"No") << '\n';
	}


}