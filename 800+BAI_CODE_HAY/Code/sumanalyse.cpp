#include <bits/stdc++.h>
using namespace std;
int n,x[100],t[100];
struct dta{
    vector <int> u;
};
bool cmp(dta a, dta b)
{

    if (a.u[0]==b.u[0]) return a.u.size()<b.u.size();
    return a.u[0]>b.u[0];
}
vector <dta> vi;
void up(int k)
{
    dta v;
    for (int i=1;i<=k;i++)
    {

        v.u.push_back(x[i]);
    }
    sort(v.u.begin(),v.u.end(),greater<int>());
    vi.push_back(v);
}
void xuat()
{
    sort(vi.begin(),vi.end(),cmp);
    for (int i=0;i<vi.size();i++)
    {
        for (int j=0;j<vi[i].u.size();j++)
        {
            cout << vi[i].u[j] << ' ';
            if (j!=vi[i].u.size()-1) cout << "+ ";
        }
        cout << '\n';
    }
}
void sinh(int i)
{
    for (int j=x[i-1];j<=((n-t[i-1])/2);j++)
    {
        x[i]=j;
        t[i]=t[i-1]+j;
        sinh(i+1);
    }
    x[i]=n-t[i-1];
    up(i);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    x[0]=1;
    sinh(1);
    xuat();
}

