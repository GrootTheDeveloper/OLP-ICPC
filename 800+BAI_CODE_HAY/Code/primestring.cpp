#include <bits/stdc++.h>
using namespace std;
int f[256];
bool nt(int n)
{
	if (n<2) return 0;
	for (int i=2;i<=sqrt(n);i++) 
		if (n%i==0) return 0;
	return 1;
}
string solve(string s)
{
	memset(f,0,sizeof(f));
	int cnt=0;
	for (char c:s)
	{
		f[(int)c]++;
		cnt+=(f[(int)c]==1);
		cnt-=(f[(int)c]==2);
	}
	return ( nt(cnt)? "YES":"NO");
}


int main()
{
	int t; cin >> t;
	string s;
	while (t--)
	{
		cin >> s;
		cout << solve(s) << '\n';
	}
}