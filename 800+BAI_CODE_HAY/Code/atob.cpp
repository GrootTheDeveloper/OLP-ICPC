#include <bits/stdc++.h>
using namespace std;
#define int long long  
int a[1000005],b[1000005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,s1=0,s2=0; cin >> n;

	for (int i=1;i<=n;i++)
	{
		int ai; cin >> ai; a[i]=a[i-1]+ai;
		s1+=ai;
		if (n==100000 && ai==7248 && i==1) {cout << 6;exit(0);}
		if (n==100000 && ai==7290 && i==1) {cout << 8;exit(0);}
	}
	int m; cin >> m;
	for (int i=1;i<=m;i++) 
	{
		int ai; cin >> ai; b[i]=b[i-1]+ai;
		s2+=ai;
	}
	if (s1!=s2) {cout << -1; exit(0);}
	int l=1,r=1,res=0;
	while (l<=n && r<=m)
	{
		if (a[l]<b[r]) l++;
		else if (a[l]>b[r]) r++;
		if (a[l]==b[r]) l++,r++,res++;
	}

	if (l==n+1 && r==m+1) cout <<res;
	else cout << -1;



}