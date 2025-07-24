#include <bits/stdc++.h>
using namespace std;
#define int long long


vector <int> xanh,doo,vang;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,xi,m; cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> xi >> m;
        if (m==1) xanh.push_back(xi);
        if (m==2) doo.push_back(xi);
        if (m==3) vang.push_back(xi);
    }
    int res=INT_MAX;
    sort(xanh.begin(),xanh.end());
    sort(doo.begin(),doo.end());
    sort(vang.begin(),vang.end());
    for (int i=0;i<xanh.size();i++)
    {
        auto itv=upper_bound(vang.begin(),vang.end(),xanh[i]);
        auto itd=upper_bound(doo.begin(),doo.end(),xanh[i]);
        if (itv!=vang.end() && itd!=doo.end()
        {
            int pos=max(*itv,*itd);
            auto it1=upper_bound(xanh.begin(),xanh.end(),pos);
            auto it2=upper_bound(doo.begin(),doo.end(),pos);
            auto it3=upper_bound(vang.begin(),vang.end(),pos);
            it1--;it2--;it3--;
            if (*it1==xanh[i] && it2==itd && it3==itv)
    }
}
