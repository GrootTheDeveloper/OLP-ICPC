#include <bits/stdc++.h>
using namespace std;
#define int long long 
char a[22];
bool f[22];
string s="RBG";
int res=0,n,k;
void Try(int i)
{
	if (i==n+1) return res++,void();
	if (f[i]==true) Try(i+1);
	for (int j=0;j<s.size();j++)
	{
		if ((a[i-1]!=s[j] && f[i+1]==false) || (a[i-1]!=s[j] && f[i+1]==true && a[i+1]!=s[j]))
		a[i]=s[j];
		Try(i+1); 
	}
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i=1;i<=k;i++) 
	{
		int x;
		char y;
		cin >> x >> y;
		a[x]=y;
		f[x]=true;
	}
	a[0]='b';
	if (n<=20) Try(1);
	cout << res;
}