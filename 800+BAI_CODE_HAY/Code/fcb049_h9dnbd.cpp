#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> vi;
unordered_map<int,int> f;

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k,ai; cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
        int ai;
        cin >> ai;
        if (f[ai]==0) vi.push_back(ai);
        f[ai]++;
    }
    int sl=0,s=0;
    for (int c : vi)
        if (f[c]>=k) sl++,s+=c;
    cout << sl << ' ' << s;

}
