#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

const int mode=998244353;
main()
{
	int a,b; 
	cin >> a >> b;
	if (a<b) swap(a,b);
	int res=0;
	while (b!=0)
	{
		int n=a/b;
		int u1=a-(n-1)*b;
		int un=a;
		res=(res+n*(u1+un)/2)%mode;
		a%=b;
		swap(a,b);
	}
	cout << res;
}