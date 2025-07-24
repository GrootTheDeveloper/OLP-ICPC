#include <bits/stdc++.h>
using namespace std;
#define int long long 
string s;
int k;
int f[1000005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> k;
	cin >> s;
	int cnt=0,res=0;
	f[0]=1;
	for (char c : s)
	{
		if (c=='H') cnt++;
		if (cnt>=k) res+=f[cnt-k];
		f[cnt]++;
	}
	cout << res;

}