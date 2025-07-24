#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	double s=0;
	for (int i=1;i<=n;i++)
	{
		if (i<=5) s+=6500;
		else if (i<=15) s+=7800;
		else if (i<=25) s+=9200;
		else if (i>25) 	s+=10300;
	}
	cout << setprecision(2) << fixed;
	cout << s << '\n';
	cout << (s*12)/100 << '\n';
	cout << s + (s*12)/100;
}