#include <bits/stdc++.h>
using namespace std;


mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
long long Rand(int l, int r)
{
	return l + rd() % (r - l + 1);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	srand(time(NULL));
	int TEST = 300;
	for (int is = 1; is <= TEST; is++)
	{	
		ofstream fout("input.inp");
		int n = Rand(1, 100);
		int m = Rand(2, 2 * n);
		fout << n << ' ' << m << '\n';
		for (int i = 1; i <= n; i++)
			fout << Rand(1, 1e5) << ' ';
		fout << '\n';
		for (int i = 1; i <= n; i++)
			fout << Rand(1, 1e5) << ' ';

		fout.close();

		system("DMAXDIF.exe");
		ifstream fin("output.out");
		int a, b; fin >> a >> b;
		fin.close();

		if (a == b) cout << "Test " << is << " : AC" << endl;
		else
		{
			cout << "Test " << is << " : Wrong";
			return 0;
		}


	}
	cout << "Perfect code!!!";





}