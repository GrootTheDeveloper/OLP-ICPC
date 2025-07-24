#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	int T1=0,T2=0;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		T2+=a[i];
	}
	int k=1,sum=INT_MAX;
	for (int i=1;i<=n-1;i++)
	{
		T1+=a[i];
		T2-=a[i];
		if (abs(T1-T2)<sum) sum=abs(T1-T2),k=i;
		
	}
	cout << k;
}