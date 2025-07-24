#include <bits/stdc++.h>
using namespace std;
int res;
string s;

main()
{
    cin >> s;
    for (char c:s) res+=('0'<=c && c<='9');
    cout << res;
}
