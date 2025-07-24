#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MAX=1e18;
struct dta{
	int val,cons=MAX;
}dp[444][444];
int a[444],n;
dta ss(dta a, dta b)
{
	if (a.cons<b.cons) return a;
	return b;
}
dta merge(dta a, dta b)
{
	dta res;
	res.cons=a.cons+b.cons+a.val+b.val;
	res.val=a.val+b.val;
	return res;
}
dta calc(int l, int r)
{
	if (l==r){
		dp[l][r].val=a[l];
		dp[l][r].cons=a[l];
		return dp[l][r];
	}
	if (dp[l][r].cons!=MAX) return dp[l][r];
	dta res;
	for (int i=l;i<r;i++)
		res=ss(res,merge(calc(l,i),calc(i+1,r)));
	dp[l][r]=res;
	return res;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	cout << calc(1,n).cons-calc(1,n).val;
}