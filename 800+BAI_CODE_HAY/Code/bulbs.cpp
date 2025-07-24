#include <bits/stdc++.h>
using namespace std;
bool check(int n)
{
    int res=0;
    for (int i=1;i<=sqrt(n);i++)
        if (n%i==0)
        res+=1+(i!=n/i);
    return (res%2==1);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        cout << check(n) << '\n';
    }
}
