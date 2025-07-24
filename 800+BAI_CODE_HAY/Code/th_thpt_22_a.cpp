#include <bits/stdc++.h>
using namespace std;
#define int long long 

main()
{
	freopen("robot.inp","r",stdin);
	freopen("robot.out","w",stdout);
	int x1,x2,y1,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	cout << max(abs(x1-x2),abs(y2-y1));

}