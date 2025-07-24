#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,divs[1000006];

void o_o()
{
	divs[0]=divs[1]=1;
	for (int i=1;i<=1e6;i+=2)
		for (int j=i*2;j<=1e6;j+=i)
			divs[j]=i;
}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	o_o();
	while (t--)
	{
		cin >> x;
		cout << divs[x] << '\n';
	}
}