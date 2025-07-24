#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int a,b; cin >> a >> b;
	int lim=(int)sqrt(a);
	int res=0;
	for (int i=1;i<=lim;i++)
	{
		if (a%i==0)
		{
			int x=i,y=a/i;
			if (b%x!=0) res+=x;
			if (y!=x && b%y!=0) res+=y; 
		}
	}
	cout << res;
}
