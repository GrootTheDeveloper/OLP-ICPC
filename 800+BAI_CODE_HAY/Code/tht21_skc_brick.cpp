#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> vi;
const int N=1000005;
bool prime[N];
void se()
{
    int t=2;
    for (int i=2;i<N;i++)
    if (!prime[i])
    {
        if (i!=2) vi.push_back(i*t),t=i;
        for (int j=i*i;j<=N;j+=i) prime[j]=true;
    }
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    se();
    int q; cin >> q;
    while(q--)
    {
        int n;
        cin >> n;
        auto it=upper_bound(vi.begin(),vi.end(),n);
        it--;
        cout << n-(*it) << endl;
    }
}
