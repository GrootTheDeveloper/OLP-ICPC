#include <bits/stdc++.h>
using namespace std;
#define int long long 

int gt(int n)
{
	if (n==1) return 1;
	return gt(n-1)*n;
}

main()
{
	cout << gt(4);
}