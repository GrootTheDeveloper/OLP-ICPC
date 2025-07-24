#include <bits/stdc++.h>
using namespace std;
const double pi=3.141592;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    double a,b,R,n;
    cin >> a >> b >> R >> n;
    R/=100;n*=1000;
    cout << (int)(n/(2*pi*R*(b/a)));
    return 0;

}
