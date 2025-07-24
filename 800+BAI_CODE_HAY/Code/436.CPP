#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,kq,a[1000007],sum;
unordered_map<int,int> dem;
main()
{
	cin >> n >> x;
	dem[0]=1;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		sum=sum+a[i];
		kq+=dem[sum-x];
		dem[sum]++;
	}
	cout << kq;
}