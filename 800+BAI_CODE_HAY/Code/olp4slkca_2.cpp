#include <bits/stdc++.h>
using namespace std;
#define int long long 


main()
{
	int a,b,c;
	cin >> a >> b >> c;
	cout << c+min(a,b)+(a-min(a,b))/3;
}