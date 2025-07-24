#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b;
int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
void sub1()
{
    vector<int> vi;
    int k=gcd(a,b);
    if (k==1) return cout << -1,void();
    for (int i=1;i<=k;i++) if (k%i==0) vi.push_back(i);
    sort(vi.begin(),vi.end());
    vi.pop_back();
    cout << vi.back();
}
void sub2()
{
    int k=gcd(a,b);
    if (k==1) return cout << -1,void();
    int lim=trunc(sqrt(k));
    int res=1;
    for (int i=2;i<=lim;i++)
    if (k%i==0)
    {
        res=k/i;
        break;
    }
    cout << res;

}
main()
{
    freopen("UOCCHUNG.INP","r",stdin);
    freopen("UOCCHUNG.OUT","w",stdout);
    cin >> a >> b;
    if (a<=1e3 && b<=1e3) sub1();
    else sub2();
}
