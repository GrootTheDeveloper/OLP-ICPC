#include <bits/stdc++.h>
using namespace std;
int f[111],day,mon,yea;
string s;
void build()
{
    f[1]=f[3]=f[5]=f[7]=f[8]=f[10]=f[12]=31;
    f[2]=29;
    f[4]=f[6]=f[9]=f[11]=30;
}
void xuli()
{
    int i=0;
    string st="";
    while (s[i]!='.') st+=s[i],i++;
    i++;day=stoi(st);st="";
    while (s[i]!='.') st+=s[i],i++;
    i++;mon=stoi(st);st="";
    while (s[i]!='.') st+=s[i],i++;
    yea=stoi(st);
}
void call(int a, int b, int c)
{
    string sd=to_string(a),sm=to_string(b),sy=to_string(c);
    while (sd.size()<2) sd='0'+sd;
    while (sm.size()<2) sm='0'+sm;
    while (sy.size()<4) sy='0'+sy;
    cout << sd << '.' << sm << '.' << sy << '.' << endl;
}
void solve()
{

    while (true)
    {
        yea++;
        int k=yea,d=0,m=0;;
        for (int i=1;i<=2;i++) d=d*10+k%10,k/=10;
        for (int i=1;i<=2;i++) m=m*10+k%10,k/=10;
        if (yea%4!=0 && m==2 && d>28) continue;
        if (d<=f[m] && d!=0)
        {
            call(d,m,yea);
            break;
        }

    }

}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    build();
    int t; cin >> t;
    while (t--)
    {
        cin >> s;
        xuli();
        solve();

    }

}
