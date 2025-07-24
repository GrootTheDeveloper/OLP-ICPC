#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b; cin >> a >> b;
    if (a<=0 && b<=0) return cout << max(a,b)-1,0;
    if (a>=0 && b>=0) return cout << min(a,b)+1,0;
    return cout << 0,0;

}
