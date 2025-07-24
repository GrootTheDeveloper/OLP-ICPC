#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> vi;
const int N=1e7+1;
bool prime[N];
void sang()
{
    for (int i=2;i<=N;i++)
    {
        if (!prime[i])
        {
            vi.push_back(i);
            for (int j=i*i;j<=N;j+=i) prime[j]=true;
        }
    }
}
void suu()
{
    int n; cin >> n;
    int k=sqrt(n);
    for (int x : vi)
    {
        if (x>k) break;
        if (n%x==0) return cout << n/x << '\n',void();

    }
    cout << -1 << '\n';
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    sang();
    while(t--)
        suu();

}
