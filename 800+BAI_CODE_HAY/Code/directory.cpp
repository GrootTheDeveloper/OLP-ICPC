#include <bits/stdc++.h>
using namespace std;
#define int long long 
string a[222];
int pos[222];
vector <string> vi;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0); 
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	int x,y;
	for (int i=1;i<n;i++) cin >> x >> y, pos[y]=x;

	for (int i=1;i<=n;i++)
	{
		int rot=i;
		while (pos[rot]!=0) vi.push_back(a[rot]),rot=pos[rot];
		cout << "root";
		while (vi.size()) cout << '/' << vi.back(),vi.pop_back();
		cout << '\n';
	}
}