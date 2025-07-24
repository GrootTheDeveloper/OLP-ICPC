#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll solve(vector <ll> x, int m)
{
    sort(x.begin(), x.end(), greater<ll>());
    ll ans=0;
    for (int i=0; i<x.size(); i+=m)
        ans+=x[i]*2;
    return ans;
}


int main()
{
    ll n,m,ai;
    cin >> n >> m;
    vector <ll> x1(n);
    vector <ll> x2(n);
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        if (ai<0) x1.push_back(-ai);
        else x2.push_back(ai);
    }
    cout << solve(x1,m) + solve(x2,m);
    return 0;
}
