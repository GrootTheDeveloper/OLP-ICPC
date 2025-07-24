#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,ai;
int a[100005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int q;cin >> q;
	q--;
	cin >> ai;
	a[1]=ai;
	n=1;
	cout << 1 << '\n';
	while (q--)
	{
		cin >> ai;
		int pos=upper_bound(a+1,a+n+1,ai)-a;
		if (pos==n+1)
		{
			n++;
			a[n]=ai;
			cout << 1 << '\n';
		}
		else
		{
			cout << n-pos+2 << '\n';
			n++;
			for (int i=n;i>pos;i--) a[i]=a[i-1];
			a[pos]=ai;
		}
		
	}
}