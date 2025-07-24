#incldue <bits/stdc++.h>
using namespace std;
#define int long long
int a[10000];

void qsort(int l,int r)
{
    int i=l,j=r;
    int p=a[(l+r)/2];
    while (i<j)
    {
        while (a[i]<p) i++;
        while (p<a[j]) j--;
        if (i<=j) swap(a[i++],a[j--]);
    }
    if (l<j) qsort(l,j);


}
