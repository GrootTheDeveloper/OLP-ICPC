#include <bits/stdc++.h>
using namespace std;
vector <int> vi;
bool f[555555];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x; cin >> n >> x;
    for (int i=1;i<=n;i++)
    {
        int ai;
        cin >> ai;
        if (!f[ai]) vi.push_back(ai);
        f[ai]=true;
    }
    sort(vi.begin(),vi.end());
    auto it=lower_bound(vi.begin(),vi.end(),x);
    return cout << it-vi.begin()+1,0;
}
