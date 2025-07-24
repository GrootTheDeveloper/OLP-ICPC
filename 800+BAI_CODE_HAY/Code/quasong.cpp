#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,k; cin >> a >> b >> c >> k;
    if (a+c<=k && k!=0 || b<=k) return cout << "YES",0;
    if (a+c>k && b>k) return cout << "NO";
    cout << "YES";

}
