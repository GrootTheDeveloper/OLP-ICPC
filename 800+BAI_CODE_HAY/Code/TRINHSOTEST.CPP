#include <bits/stdc++.h>
using namespace std;
//#define int long long
mt19937_64 rd(time(NULL));

int Rand(int L, int R)
{
	return L + rd() % (R - L + 1);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	srand(time(NULL));
	for (int istest = 1; istest <= 1; istest++){
		ofstream fout("test.inp");
		int n = Rand(1, 1000);
		fout << n << '\n';
		for (int i = 1; i <= n; i++)
			fout << Rand(1, 1000) << ' ';
		fout.close();

		// system("seq2sc.exe");
		// ifstream fin("test.out");
		// long long a, b; fin >> a >> b;
		// fin.close();
		
		// if (a == b) cout << "ACCEPTED!" << endl;
		// else return cout << "Wrong anwer on test " << istest, 0;
	}
	
}
