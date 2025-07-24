#include <bits/stdc++.h>
using namespace std;
#define int long long 

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count())

int Rand(int L, int R)
{
	return L + rd() % (R - L + 1);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for (int is = 1; is <= 100; is++)
	{
		ofstream fout("input.inp");
		int n = Rand()


		fout.close();
		system(".exe")
		ifstream fin("output.out");



		fout.close();
	}
}

