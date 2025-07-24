#include <bits/stdc++.h>
using namespace std;
#define int long long
int bang=0,bl=0;
struct dta{ int p,type;};
dta a[300005];
bool cmp(dta a, dta b) 
{
	return a.p<b.p;
}

void pull(int pos) 
{
	if (a[pos].type==1) bang++;
	else bl++;
}
void dell(int pos)
{
	if (a[pos].type==1) bang--;
	else bl--;
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,x,y; cin >> n >> x >> y;
	for (int i=1;i<=n;i++) cin >> a[i].p >> a[i].type;
	sort(a+1,a+n+1,cmp);
	int l=1,res=INT_MAX;
	for (int i=1;i<=n;i++)
	{
		pull(i);
		while (bang>=x && bl>=y) res=min(res,a[i].p-a[l].p),dell(l++);
	}
	if (res==INT_MAX) res=-1;
	cout << res;
}