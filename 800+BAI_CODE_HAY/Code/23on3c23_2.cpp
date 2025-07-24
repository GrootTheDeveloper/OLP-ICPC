#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int base=311,mode=1e17+7;
unordered_map <int,int> f;
string a[50004];

bool sub(const string &A, const string &B)
{
	if (A.size()>B.size()) return 0;
	for (int i=0;i<A.size();i++) if (A[i]!=B[i]) return 0;
	return 1;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int res=0;
	for (int i=1;i<=n;++i)
		for (int j=i+1;sub(a[i],a[j]);++j) res++;
	cout << res;
}