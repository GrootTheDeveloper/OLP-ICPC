#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo=INT_MAX,o_o=INT_MIN;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0); 
	int n; cin >> n;
	int ymin=INT_MAX , ymax=INT_MIN;
	int xmax=INT_MIN , xmin=INT_MAX;
	for (int i=1;i<=n;i++)
	{
		int x,y; cin >> x >> y;
		xmax=max(xmax,x);
		xmin=min(xmin,x);
		ymax=max(ymax,y);
		ymin=min(ymin,y);
	}
	//(ymax-ymin)^2 , (xmax-xmin)^2
	cout << max(pow(ymax-ymin,2),pow(xmax-xmin,2));
}