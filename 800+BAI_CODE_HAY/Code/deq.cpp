#include <bits/stdc++.h>
using namespace std;

int a[100005],b[100005];

main()
{
	
	int n; cin >> n; 
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++)
	{
		if (a[i]>=a[i-1]) b[i]=i-1;
		else
		{
			int j=b[i-1];
			while (a[j]>a[i]) j=b[j];
			b[i]=j;
	
		}
	}
	for (int i=1;i<=n;i++) cout << a[b[i]] << ' ';
}
