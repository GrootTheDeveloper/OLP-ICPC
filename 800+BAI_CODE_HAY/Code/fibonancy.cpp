#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int,bool> f;
const int N=1e10;
void sang()
{
    int a=0,b=1,c=1;
    f[0]=true;
    f[1]=true;
    while (c<N)
    {
        int temp=b;
        c=a+b;
        a=temp;
        b=c;
        f[c]=true;
    }
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    sang();
    while (t--)
    {
        int n; cin >> n;
        cout << ((f[n])? "IsFibo":"IsNotFibo") << '\n';
    }
}
