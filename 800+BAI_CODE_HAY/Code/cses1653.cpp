#include <bits/stdc++.h>
using namespace std;
vector <int> vi;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,x; cin >> n >> x;
    for (int i=1;i<=n;i++)
    {
        int ai;
        cin >> ai;
        vi.push_back(ai);
    }
    sort(vi.begin(),vi.end());
    int res=0;
    while (vi.size())
    {
        int w=x;
        while (upper_bound(vi.begin(),vi.end(),w)-vi.begin()!=0)
        {
            auto it = upper_bound(vi.begin(),vi.end(),w);
            it--;
            w=w-(*it);
            cout << *it << ' ';
            vi.erase(it);
        }
        cout << endl;
        res++;
    }
    return cout << res,0;

}
