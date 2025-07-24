#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n,c,s;
    cin >> n >> c >> s;
    long long x=n/15;
    cout << n*c-s*x;
    return 0;
}
