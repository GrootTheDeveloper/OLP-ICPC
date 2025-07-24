#include <bits/stdc++.h>
using namespace std;
#define int long long 
int s(int n)
{
	int res=0;
	while(n) res+=n%10,n/=10;
	return res;
}
main()
{
	/*int t=2;
	while (t--)
	{
		int n,k; cin >> n >> k;
		int i=k,res=0;
		while (i<=n)
		{
			res+=s(i);
			i+=k;
		}
		cout <<  res << '\n';
	}*/
	int n,k; cin >> n >> k;
	int i=k;
	while (i<=n)
	{
		cout << i << ' ' << s(i) << endl;
		i+=k;
	}
}