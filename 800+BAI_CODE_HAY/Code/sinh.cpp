#include <bits/stdc++.h>
using namespace std;
#define int long long 

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int L, int R)
{
	return L + rd() % (R - L + 1);
}

signed main()
{
    freopen("input.txt","w",stdout);
    int n = Rand(40000, 100000);
    int d = Rand(10000, 100000000);
    cout << n << ' ' << d << '\n';
    for (int i = 1; i <= n; i++)
        cout << Rand(10000, 100000) << ' ';
}
