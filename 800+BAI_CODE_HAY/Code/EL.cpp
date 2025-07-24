#include <bits/stdc++.h>
using namespace std;
vector <string> vi;
unordered_map <string,string> f;
int sc=10;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l, int h)
{
	return l+rd()%(h-l+1);
}
string xuli(string s)
{
	while (s.back()==' ') s.pop_back(); 
	return s;
}

void solve()
{
	
	for (int i=0;i<vi.size();i++)
	{
		cout << vi[i] << " :" << endl;
		string s;getline(cin,s);
		s=xuli(s);
		if (s==f[vi[i]]) cout << "ACCEPTED" << endl;
		else cout << "DOT NAT!!! EXPECTED : " << f[vi[i]] << endl, sc--;
		cout << endl;
		cout << endl;
	}	
}
void solve2()
{
	for (int i=0;i<vi.size();i++)
	{
		cout << f[vi[i]] << " :" << endl;
		string s;getline(cin,s);
		s=xuli(s);
		if (s==f[f[vi[i]]]) cout << "ACCEPTED" << endl;
		else cout << "DOT NAT!!! EXPECTED : " << f[f[vi[i]]] << endl,sc--;
		cout << endl;
		cout << endl;
	}	
}
void test()
{
	int t=5;
	while (t--)
	{
		int i=Rand(0,vi.size()-1);
		cout << vi[i] << " :" << endl;
		string s;getline(cin,s);
		s=xuli(s);
		if (s==f[vi[i]]) cout << "ACCEPTED" << endl;
		else cout << "NOT NAT!!! EXPECTED : " << f[vi[i]] << endl,sc--;
		cout << endl;
		cout << endl;

	}
}
main()
{
	vi.push_back("to work out");f[vi.back()]="tap the duc";f[f[vi.back()]]=vi.back();
	vi.push_back("be full of");f[vi.back()]="tran day";f[f[vi.back()]]=vi.back();
	vi.push_back("diet");f[vi.back()]="bua an";f[f[vi.back()]]=vi.back();
	vi.push_back("balanced");f[vi.back()]="can bang";f[f[vi.back()]]=vi.back();
	vi.push_back("fit");f[vi.back()]="can doi";f[f[vi.back()]]=vi.back();

	

	solve();
	solve2();
	//test();
	if (sc==10) cout << "PER FET";
}
//vi.push_back("");f[vi.back()]=="";f[f[vi.back()]]=vi.back();