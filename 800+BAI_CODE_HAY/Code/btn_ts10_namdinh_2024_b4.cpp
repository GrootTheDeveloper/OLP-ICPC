#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1111];
map <pair<int,int>,bool> f;
unordered_map <int,int> cnt;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i],cnt[a[i]]++;
	int res=0;
	for (int i=1;i<n;i++) 
	{
		for (int j=i+1;j<=n;j++) 
			if (cnt.find(a[i]+a[j])!=cnt.end() && f.find({a[i],a[j]})==f.end() && f.find({a[j],a[i]})==f.end())
			{
				res+=cnt[a[i]+a[j]];
				f[{a[i],a[j]}]=true;
				f[{a[j],a[i]}]=true;
			}
	
	}
	cout << res;
	
}