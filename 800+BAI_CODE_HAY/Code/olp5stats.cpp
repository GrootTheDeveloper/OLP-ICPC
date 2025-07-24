#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10005];
unordered_map <int,int> f;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	int sum=0;
	for (int i=1;i<=n;i++) cin >> a[i],sum+=a[i],f[a[i]]++;
	sort(a+1,a+n+1);
	cout << a[n] << '\n' << a[1] << '\n';
	double avg=(double)sum/n;
	cout << setprecision(12) << fixed << avg << '\n';
	cout << a[n/2+1] << '\n';
	int mode=0;
	for (int i=1;i<=n;i++) if (f[mode]<f[a[i]]) mode=a[i];
	cout << mode << '\n';
	double res=0;
	for (int i=1;i<=n;i++)
		res+=(a[i]-avg)*(a[i]-avg);
	cout << setprecision(12) << fixed << sqrt(res/n);


}