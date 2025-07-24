#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	int x1,x2,x3,y1,y2,y3;
	while (t--)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		int k=(y1-y2)*(x3-x1)+(x2-x1)*(y3-y1);
		if (k==0) cout << "TOUCH";
		else
		{
			if (k<0) cout << "RIGHT";
			else cout << "LEFT";
		}
		cout << '\n';
	}
}