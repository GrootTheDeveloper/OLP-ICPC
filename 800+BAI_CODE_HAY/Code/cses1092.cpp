#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> vi;
vector <int> sol;
main()
{
    int n; cin >> n;
    int s=n*(n+1)/2;
    if (s&1) return cout << "NO",0;
    else cout << "YES" << endl;
    for (int i=1; i<=n; i++) vi.push_back(i);
    s/=2;
    while (s!=0)
    {
        auto it=upper_bound(vi.begin(),vi.end(),s);
        it--;
        s-=*it;
        sol.push_back(*it);
        vi.erase(it);

    }
    cout << vi.size() << endl;
    for (int i=0; i<vi.size(); i++) cout << vi[i] << ' ';
    cout << endl;
    cout << sol.size() << endl;
    for (int i=0; i<sol.size(); i++) cout << sol[i] << ' ';

}
