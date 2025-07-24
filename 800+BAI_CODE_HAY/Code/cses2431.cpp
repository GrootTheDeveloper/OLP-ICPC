#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long 

int d[20];
vector <int> v;
void init()
{
	for (int i=1;i<=18;i++)
		d[i]=(pow(10,i)-pow(10,i-1))*i;
	for (int i=1;i<=18;i++) d[i]+=d[i-1];
	for (int i=0;i<=18;i++)
		v.push_back(pow(10,i));
}
int fast(int n)
{
	string s=to_string(n);
	int lim=s.size();
	auto it=upper_bound(v.begin(),v.end(),n);
	it--;
	return (d[lim-1]+(n-(*it)+1)*lim);
}

char calc(int n)
{
	int l=1,r=(int)1e18;
	while (l<r)
	{
		int mid=(l+r)/2;
		if (fast(mid)>n) r=mid-1;
		else l=mid+1;
	}
	while (fast(l-1)>=n) l--;
	while (fast(l)<n) l++;
	int lim=fast(l-1);
	string s=to_string(l);
	int i=-1;
	while (lim<n) lim++,i++;
	return s[i];
	
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	init();
	int t; cin >> t;
	int x;
	while (t--)
	{
		cin >> x;
		cout << calc(x) << '\n';
	}
	//for (int i=1;i<=18;i++) cout << d[i] << ' ' << p[i] << endl;
}