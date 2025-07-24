#include <bits/stdc++.h>
using namespace std;



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);; cout.tie(0);
	double x1, y1, vx1, vy1; cin >> x1 >> y1 >> vx1 >> vy1;
	double x2, y2, vx2, vy2; cin >> x2 >> y2 >> vx2 >> vy2;

	if ((x1 - x2) * (vy2 - vy1) == (y1 - y2) * (vx2 - vx1))
	{
		double t = (double)(x1 - x2) / (vx2 - vx1);
		if (t >= 0.0) cout << fixed << setprecision(4) << t * vx1 + x1 << ' ' << t * vy1 + y1;
		else cout << "-1";
	} else cout << "-1";
}