#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,a[200005];
vector <int> p;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++)
	{
		while (p.size()){
		if (a[p.back()]>=a[i]) p.pop_back();
		else break;}
		if (p.size()==0) cout << 0 << ' ';
		else cout << p.back() << ' ';
		p.push_back(i);

	}
}