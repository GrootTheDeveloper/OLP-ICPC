#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    cout << fixed << setprecision(1);
    while(t--)
    {
        int n,a,b; cin>>n>>a>>b;
        cout<<(double) 4 *n / (b*3.14 + 4*a)<<'\n';
    }
}
