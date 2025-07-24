#include <bits/stdc++.h>
using namespace std;
#define int long long 

int op[5][3] = {{0,2,1}, {1,0,2}, {2,2,0}, {3,0,1}, {5,0,0}};
int B[5] = {0, 1, 2, 3, 4};

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int a, b, c; cin >> a >> b >> c;
		int x = a, y = b, z = c;
		int ans = 0;
		for (int i = 0; i < 5; i++)
		{
			int k = 1e18;
			if (op[i][0]) k = min(k, x / op[i][0]);
			if (op[i][1]) k = min(k, y / op[i][1]);
			if (op[i][2]) k = min(k, z / op[i][2]); 
			ans += k;
			x -= k * op[i][0];
			y -= k * op[i][1];
			z -= k * op[i][2];
		}
		cout << ans << '\n';
	}
}