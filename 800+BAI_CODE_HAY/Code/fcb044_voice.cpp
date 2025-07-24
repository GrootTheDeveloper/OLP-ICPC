#include <bits/stdc++.h>
using namespace std;
vector <int> vi;
vector <int> l;
int a[3333];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    if (n==1) return cout << 1,0;
    for (int i=2;i<=n;i++)
        l.push_back((a[i]<a[i-1])? -1:1);
    int t=0;
    for (int i=0;i<l.size();i++)
    {
        if (i==0)
        {
            t+=l[i];
            continue;
        }
        if (l[i]==l[i-1]) t+=l[i];
        else
        {
            vi.push_back(t);
            t=l[i];
        }

    }
    vi.push_back(t);
    int MAX=abs(vi[0]);
    for (int i=1;i<vi.size();i++)
    {
        MAX=max(abs(vi[i]),MAX);
        if (vi[i]<0 && vi[i-1]>0) MAX=max(abs(vi[i]-vi[i-1]),MAX);
    }
    return cout << MAX+1,0;

}

