#include <bits/stdc++.h>
using namespace std;
#define int long long 
int l[1000006],r[1000006];

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	string s;
	cin >> s;
	s="#"+s;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='L')
			for (int j=i-1;j>=1;j--)
			{
				if (s[j]=='.')
					r[j]=r[j+1]+1;
				else break;
			}
		if (s[i]=='R') 
			for (int j=i+1;j<=n;j++)
			{
				if (s[j]=='.') l[j]=l[j-1]+1;
				else break;
			}		
	}
	int res=0;
	for (int i=1;i<=n;i++)
	{
		if (s[i]=='.' && r[i]==l[i]) res++;
	}
	cout << res;
	


}