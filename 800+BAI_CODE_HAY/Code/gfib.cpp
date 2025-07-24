#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[1111],ans;
unordered_map <int,vector<int>> f;
void Try(int val1, int val2, int pos, int res)
{
	if (f[val1+val2].empty()) return ans=max(ans,res),void();
	int t=upper_bound(f[val1+val2].begin(),f[val1+val2].end(),pos)-f[val1+val2].begin();
	if ((int)t!=(int)f[val1+val2].size()) Try(val2,a[f[val1+val2][t]],f[val1+val2][t],res+1);
	else return ans=max(ans,res),void();
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i],f[a[i]].push_back(i);
	for (int i=1;i<=n-1;i++) for (int j=i+1;j<=n;j++)
	Try(a[i],a[j],j,2);
	cout << n-ans;
}