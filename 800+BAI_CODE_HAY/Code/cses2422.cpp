#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,idx;

bool check(int x)
{
	for (int i=1,count=0;i<=n;++i)
	{
		count+=min(n,x/i);
		if (count >= idx) return 1;
	}
	return 0;
}
signed main()
{
	cin >> n;
	idx=n*n/2+1;
	int l=1,r=(int)1e12;
	while (l<r) 
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	while (check(l-1)) l--;
	while (!check(l))  l++;
	cout << l;
}