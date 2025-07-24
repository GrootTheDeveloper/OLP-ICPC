#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,k,a[100000];
unordered_map <int,int> f;
void sub1()
{
	int mx=INT_MIN,mi=INT_MAX;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		f[a[i]]++;
		mx=max(mx,a[i]);
		mi=min(mi,a[i]);
	}
	int k=INT_MIN;
	if (f[mx]>1) cout << 2*mx-mi;
	else  
	{
		for (int i=1;i<=n;i++)
			if (a[i]!=mx) k=max(k,a[i]);
		cout << k+mx-mi;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	if (k==1) sub1();

}