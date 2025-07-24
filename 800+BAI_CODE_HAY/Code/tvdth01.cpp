#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
	int n; cin >> n;
	int res=1,k=1;
	while (true)
	{
		if (n>=k)
		{
			n-=k;
			k+=2;
			if (k!=0) res++;
		}
		else return cout << res,0;
	}

}