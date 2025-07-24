#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+1;
bool prime[N];
int divs[N];
void siuuu()
{
    for (int i=2;i<=sqrt(N);i++)
        if (!prime[i])
        {
            divs[i]=i;
            for (int j=i*i;j<=N;j+=i)
            {
                divs[j]=i;
                prime[j]=true;
            }
        }

}
void solve(int n)
{
    vector <int> vi;
    while (n!=1)
    {
        if (!prime[n]) {vi.push_back(n);break;}
        vi.push_back(divs[n]);
        n/=divs[n];
    }
    sort(vi.begin(),vi.end());
    for (int i=0;i<vi.size()-1;i++)
        cout << vi[i] << '*';
    cout << vi[vi.size()-1] << endl;

}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    siuuu();
    while (t--)
    {
        int n; cin >> n;
        solve(n);
    }
}
