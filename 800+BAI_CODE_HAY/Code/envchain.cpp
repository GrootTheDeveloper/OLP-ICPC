#include <bits/stdc++.h>
using namespace std;
#define int long long 
int dp[5555],last[5555],W,H;
struct node{
	int wi,hi,idx;
}a[5555];
bool cmp(node a, node b)
{
	if (a.wi == b.wi) return a.hi < b.hi;
	return a.wi < b.wi;
}
bool checking(int &i, int &j) 
{
	return a[j].wi>W && a[j].hi>H && a[j].wi<a[i].wi && a[j].hi<a[i].hi;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,W,H; cin >> n >> W >> H;
	for (int i=1;i<=n;++i) cin >> a[i].wi >> a[i].hi,a[i].idx=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;++i)
	{
		if (a[i].wi > W && a[i].hi > H)
		{
			dp[i]=1;
			for (int j=i-1;j>=1;--j)
				if (checking(i,j) && dp[j]+1>dp[i]) dp[i]=dp[j]+1,last[i]=j;  
		}
	}
	
	//Tìm phương án tối ưu
	int pos=0;
	for (int i=1;i<=n;i++) if (dp[i]>dp[pos]) pos=i;
	cout << dp[pos] << '\n';
	
	//Try vết
	vector <int> v;
	while (pos!=0)
	{
		v.push_back(a[pos].idx);
		pos=last[pos];
	}
	reverse(v.begin(),v.end());
	for (int &c : v) cout << c << ' ';

}