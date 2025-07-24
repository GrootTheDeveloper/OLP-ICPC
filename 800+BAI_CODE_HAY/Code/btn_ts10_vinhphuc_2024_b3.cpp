#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt1[1000006],cnt2[1000006],a[1000006];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q; cin >> n >> q;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int count=1;
	for (int i=1;i<=n;i++)
		if (a[i]!=a[i+1]) cnt1[count]++,count=1;
		else count++;

	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	count=1;
	for (int i=1;i<=n;i++)
		if (a[i]!=a[i+1]) cnt2[count]++,count=1;
		else count++;

	for (int i=1;i<=n;i++) cnt1[i]+=cnt1[i-1],cnt2[i]+=cnt2[i-1];
	while (q--)
	{
		int x;
		cin >> x;
		cout << cnt1[n]-cnt1[x-1] << ' ' << cnt2[n]-cnt2[x-1] << '\n'; 
	}
	

}