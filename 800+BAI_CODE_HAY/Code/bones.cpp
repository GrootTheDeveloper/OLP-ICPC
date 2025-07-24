#include <bits/stdc++.h>
using namespace std;
#define int long long 
int cnt[100];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int a,b,c; cin >> a >> b >> c;
	for (int i=1;i<=a;i++)
	for (int j=1;j<=b;j++)
	for (int z=1;z<=c;z++)
		cnt[i+j+z]++;
	int res=0;
	for (int i=3;i<=a+b+c;i++)
	if (cnt[i]>cnt[res]) res=i;
	cout << res;
}