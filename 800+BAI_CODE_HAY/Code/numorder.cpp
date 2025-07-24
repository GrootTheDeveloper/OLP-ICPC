#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,k;

bool check(int x)
{
	int cnt=0;
	for (int i=1;i<=m;i++)
	{
		cnt+=min(n,(int)sqrt(x-i*i));
		if (cnt>=k) return true;
	}
	return false;
}


signed main()
{
	//ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> m >> n >> k;
	if (m>n) swap(m,n);
	
	int l=1,r=(int)1e17;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	while (check(l-1)) l--;
	while (!check(l)) l++;
	cout << l;
}