#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("tuvung.inp","r",stdin);
	freopen("tuvung.out","w",stdout);
	string s; cin >> s;
	int cnt1=0,cnt2=0,res=0;
	for (char c : s)
	{
		if (c=='e' || c=='u' || c=='o' || c=='a' || c=='i') cnt1++,res+=cnt2;
		else cnt2++,res+=cnt1;
	}
	cout << res;
}