#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[10000000],n,s;
int main(){
	cin>>n;
	for (ll i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (ll i=1; i<=n; i++)
	{
		for (ll j=i+1; j<=n; j++)
		{
			s+=a[j]-a[i];
		}
	}
	cout<<s;
}
