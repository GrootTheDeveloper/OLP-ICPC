#include <bits/stdc++.h>
using namespace std;
#define int long long

string s;
int f[256];

main()
{
	cin >> s;
	for (char c: s) f[(int)c]++;
	int s=0;
	char temp;
	for (int i='A';i<='Z';i++) if (f[i]%2==1) s++,temp=(char)i;
	if (s>1) {cout << "NO SOLUTION";exit(0);}
	if (s) f[(int)temp]--;
	for (int i='A';i<='Z';i++)  
	{
		int k=f[i]/2;
		while (k--) cout << (char)i;
	}
	if (s) cout << temp;
	for (int i='Z';i>='A';i--)  
	{
		int k=f[i]/2;
		while(k--) cout << (char)i;
	}
	
}