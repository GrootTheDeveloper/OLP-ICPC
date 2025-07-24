#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long 

main()
{
	int n; cin >> n;
	int k=n/2+1;
	cout << k*(2+(k-1)*2)/2;
}