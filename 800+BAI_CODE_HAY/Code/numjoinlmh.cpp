#include <bits/stdc++.h>
using namespace std;
#define int long long 

string a[100005];
bool cmp(string a, string b)
{
	return a+b>b+a;
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n; 
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++) cout << a[i];
}