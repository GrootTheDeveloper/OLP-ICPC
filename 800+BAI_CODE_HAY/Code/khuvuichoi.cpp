#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int a,b; cin >> a >> b;
	int cnt=0,res=0;
	for (int i=a;i<b;i++)
	{
		cnt++;
		int k;
		if (i<12) k=6;else k=10;
		if (cnt>4) k/=2;
		res+=k;
	}
	cout << res;
}