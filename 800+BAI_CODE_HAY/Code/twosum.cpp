#include <bits/stdc++.h>
using namespace std;
#define int long long 

unordered_map <int,int> f;
int a[5555];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	int res=0;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		a[i]+=a[i-1];
		for (int j=i-1;j>=1;j--)
			if ((a[i]-a[j-1])%2==0 && f.find(a[j-1]+(a[i]-a[j-1])/2)!=f.end()) res=max(res,i-j+1);
		if (f.find(a[i])==f.end()) f.insert({a[i],i});
	}
	cout << res;
}