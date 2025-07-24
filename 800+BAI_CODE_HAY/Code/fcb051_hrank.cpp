#include <bits/stdc++.h>
using namespace std;
struct data{
    int id;
    int val;
};
struct cmp{
    bool operator() (data x, data y)
    {
        return x.val < y.val;
    }

};
set <data , cmp> sol;
set <data> :: iterator it;
vector <data> vi;
int a[1111];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q; cin >> n >> q;
    data x;
    x.id=1;x.val=1;sol.insert(x);
    for (int i=2;i<=n;i++)
    {
        int k; cin >> k;
        if (k==0)
        {
            it=sol.end();
            it--;
            data t=*it;
            x.id=i;
            x.val=t.val+1;
            sol.insert(x);
            continue;
        }
        while (k--)
        {
            it=sol.end();
            it--;
            data t=*it;
            t.val++;
            vi.push_back(t);
            sol.erase(it);
        }
        x.id=i;
        x.val=vi[vi.size()-1].val-1;
        sol.insert(x);
        while (vi.size())
        {
            sol.insert(vi[vi.size()-1]);
            vi.pop_back();
        }
    }
    int vt=0;
    for (it=sol.begin();it!=sol.end();it++)
    {
        vi.push_back(*it);
    }
    int k=0;
    for (int i=vi.size()-1;i>=0;i--)
    {
        k++;
        a[vi[i].id]=k;
    }
    while (q--)
    {
        int i;
        cin >> i;
        cout << a[i] << endl;
    }

}
