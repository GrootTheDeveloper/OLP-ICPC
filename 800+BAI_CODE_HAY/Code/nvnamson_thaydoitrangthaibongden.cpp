#include <bits/stdc++.h>
using namespace std;
#define int long long

int calc(int n)
{
	// Trả về số lượng số cp <= n 
	return trunc(sqrt(n));
}
signed main()
{
	int a,b,n; cin >> a >> b >> n;
	// Chỉ cần tính số lượng số chính phương trong đoạn [a,b]
	cout << calc(b) - calc(a-1);

}