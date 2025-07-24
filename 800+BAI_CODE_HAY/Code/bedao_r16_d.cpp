#include <bits/stdc++.h>
using namespace std;
struct data{
    int fi,se,id;
};
data a[111111];
vector <int> vi;
bool cmp(data a, data b)
{
    return a.fi+a.se>b.fi+b.se;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    int s1=0,s2=0;
    for (int i=1;i<=n;i++) cin >> a[i].fi, a[i].id=i, s1+=a[i].fi;
    for (int i=1;i<=n;i++) cin >> a[i].se, s2+=a[i].se;
    sort(a+1,a+n+1,cmp);
    int res=abs(s1-s2);
    for (int i=1;i<=n;i++)
    {
        int sol1=s1-a[i].fi+a[i].se;
        int sol2=s2-a[i].se+a[i].fi;
        if (res>abs(sol1-sol2))
        {
            res=abs(sol1-sol2);
            s1=sol1;
            s2=sol2;
            vi.push_back(a[i].id);
        }
    }
    cout << res << endl;
    sort(vi.begin(),vi.end());
    cout << vi.size() << ' ';
    for (int c : vi) cout << c << ' ';
    return 0;
}
