#include <bits/stdc++.h>
using namespace std;
#define int long long

int calc(int n)
{
	int res=0;
	res+=n/3+n/7+n/5;
	res=res-n/15-n/21-n/35;
	res+=n/105;
	return res;
}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int k; cin >> k;
	int l=1,r=(int)1e18;
	while (l<r)
	{
		int mid=(l+r)/2;
		int x=calc(mid);
		if (x<k) l=mid+1;
		else r=mid-1;
	}
	while (calc(l)<k) l++;
	while (calc(l-1)>=k) l--;
	while (l%3!=0 && l%5!=0 && l%7!=0) l--;
	cout << l;

}