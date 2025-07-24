#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a,b;

bool nto(int n)
{
    if (n<2) return false;
    int lim=trunc(sqrt(n));
    for (int i=2;i<=lim;i++) if (n%i==0) return 0;
    return true;
}
void sub1()
{
    int lim=trunc(sqrt(n)),res=0;
    for (int i=2;i<=lim;i++) if (nto(i)) res++;
    cout << res << ' ';
}


bool prime[4000005];
int f[4000005],d[4000005];
vector <int> p;
void sang(int N)
{
    int lim=trunc(sqrt(N));
    for (int i=2;i<=lim;i++) if (!prime[i])
        for (int j=i*i;j<=N;j+=i) prime[j]=true;
    for (int i=2;i<=N;i++) if (!prime[i]) p.push_back(i);
    for (int i=1;i<=N;i++) f[i]=1,d[i]=1;
    for (int i=2;i<=N;i++)
    for (int j=i;j<=N;j+=i) d[j]++;


   for (int c : p)
        for (int i=c;i<=N;i+=c) f[i]=f[i]*c;
}
void sub2()
{
    sang(n);
    int res=0;
    for (int i=2;i<=n;i++) res+=(i*f[i]<=n && a<=d[i] && d[i]<=b);
    cout << res;
}
main()
{
    cin >> n >> a >> b;
    if (n<=1e6 && a==2 && b==2) sub1();
    else if (a==2 && b==4 && n<=4e6) sub2();

}
