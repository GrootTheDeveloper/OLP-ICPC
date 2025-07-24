#include <bits/stdc++.h>
using namespace std;
#define int long long
int l[1000006],r[1000006],a[1000006];
int gcd(int a, int b)
{
	return __gcd(a,b);
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i],l[i]=gcd(l[i-1],a[i]);
	for (int i=n;i>=1;i--) r[i]=gcd(r[i+1],a[i]);
	int ans=0;
	for (int i=1;i<=n;i++)
		ans=max(ans,gcd(l[i-1],r[i+1]));
	cout << ans;

}