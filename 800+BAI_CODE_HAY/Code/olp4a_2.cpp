#include <bits/stdc++.h>
using namespace std;
#define int long long 
int c[4],d[4];
unordered_map <int,int> cnt;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int ai;
	for (int i=1;i<=3;i++)
	for (int j=1;j<=3;j++)
	{
		cin >> ai;
		d[i]+=ai;
		c[j]+=ai;
		cnt[ai]++;
	}
	if (d[1]==d[2] && d[2]==d[3] && d[3]==c[1] && c[1]==c[2] && c[2]==c[3] && cnt[ai]!=9)
	cout << "YES";
	else cout << "NO";	
}