#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
int a[MAX],n;

/*void quicksort(int a[], int l, int r)
{
    int p=a[(l+r)/2];
    int i=l,j=r;
    while (i<j)
    {
        while (a[i]<p) i++;
        while (a[j]>p) j--;
        if (i<=j) swap(a[i++],a[j--]);
    }
    if (i<r) quicksort(a,i,r);
    if (l<j) quicksort(a,l,j);
}*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        cout << a[i] << ' ';
    return 0;
}
