#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
bool prime[5000006];
void sie()
{
    int lim=trunc(sqrt(5000004));
    prime[0]=prime[1]=true;
    for (int i=2;i<=lim;i++)
    if (!prime[i]) for (int j=i*i;j<=5e6;j+=i) prime[j]=true;
}

void o_o()
{
    sie();
    int cnt=0,p=0;
    s='#'+s+'#';
    for (int i=1;i<s.size()-1;i++)
        if (s[i]>='0' && s[i]<='9')
        {
            cnt++;
            string st="";
            if (s[i-1]>='0' && s[i-1]<='9') continue;
            else
            {
                for (int j=i;s[j]>='0' && s[j]<='9';j++)
                st+=s[j];
                int k=stoll(st);
                if (!prime[k]) p=max(p,k);
            }

        }
    cout << cnt << '\n' << p;
}




main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> s;
    o_o();
}
