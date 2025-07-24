#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long



int calc(int n)
{
	int res=n;
	res=res-n/2-n/3-n/7-n/5;
	res=res+n/6+n/10+n/14+n/21+n/15+n/35;
	res=res-(n/30+n/42+n/105+n/70)+(n/210);   
	return res;
}
 
void solve()
{
	int v,k; cin >> v >> k;
	cout << calc(v) << ' ';
	int l=1,r=(int)1e19;
	while (l<r)
	{
		int mid=(l+r)/2;
		int x=calc(mid);
		if (x==k) {l=mid;break;}
		if (x<k) l=mid+1; 
		else r=mid-1;
	}
	while (l%2==0 || l%3==0 || l%5==0 || l%7==0) l--;
	cout << l << '\n';

}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
	
}