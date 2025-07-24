#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dt{
    int MIN,MAX;
};
dt f[11];
int a[11],n;
int tich(int arr[],int k)
{
    int s=0;
    for (int i=1;i<=k;i++) s=s*10+arr[i];
    return s;
}
int solve(int n, int k)
{
    int s[k+1];
    int b[k+1];
    for (int i=1;i<=k/2;i++) s[i]=4,s[i*2+i%2]=7;
    for (int i=k;i>0;i--) b[abs(i-k-1)]=a[i];
    int j=k/2+1,index=1;
    while (j<=k){
        int i=index;
        while (i<j)
        {
            if (b[i]>=s[i])
            {
                swap(s[i],s[j]),index=i+1;
                if (tich(s,k)>n) return tich(s,k);
                break;
            }
        }
        j++;
        }
    return tich(s,k);
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    f[2].MIN=47;f[2].MAX=74;
    f[4].MIN=4477;f[4].MAX=7744;
    f[6].MIN=444777;f[6].MAX=777444;
    f[8].MIN=44447777;f[8].MAX=77774444;
    f[10].MIN=4444477777;f[10].MAX=7777744444;
    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int temp=n;
        int dem=0;
        while (temp!=0) dem++,a[dem]=temp%10,temp/=10;
        dem+=dem%2;
        if (n<=f[dem].MIN) cout << f[dem].MIN << endl;
        else if (n==f[dem].MAX) cout << f[dem].MAX << endl;
        else if (n>f[dem].MAX) cout << f[dem+2].MIN << endl;
        else cout << solve(n,dem) << endl;
    }
}


