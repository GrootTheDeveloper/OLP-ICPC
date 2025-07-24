#include <bits/stdc++.h>
using namespace std;
#define int long long 
int l,r,cnt[1000006],divs[1000006];
bool f[1000006];

void sang()
{
	int N=1e6;
	for (int i=2;i<=N;i++)
	if (!divs[i]) for (int j=i;j<=N;j+=i) divs[j]=i;
}
int pt(int n)
{
	vector <int> v;
	while (n!=1)
	{
		if (!f[divs[n]]) v.push_back(divs[n]),f[divs[n]]=1;
		n/=divs[n];
	}
	int sum=1;
	for (int c : v) sum*=c,f[c]=false; 
	return sum;
}
void solve()
{
	sang();
	int res=0;
	for (int i=l;i<=r;i++) cnt[pt(i)]++;
	for (int i=2;i<=r;i++)
		if (cnt[i]>1) res+=(cnt[i]*(cnt[i]-1))/2;
	cout << res;

}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	cin >> l >> r;
	
	solve();
	
}