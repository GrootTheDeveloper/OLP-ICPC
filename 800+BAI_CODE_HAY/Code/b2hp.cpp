#include <bits/stdc++.h>
using namespace std;
#define int long long 
string s;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("b2.inp","r",stdin);
	freopen("b2.out","w",stdout);
	cin >> s;
	int l=0,r=(int)s.size()-1;
	for (l;l<r;l++) if (s[l]=='1') break;
	for (r;r>=0;r--) if (s[r]=='1') break;
	int res=0;
	for (int i=l;i<=r;i++) res+=(s[i]=='0');
	cout << res;
}