#include <bits/stdc++.h>

using namespace std;
long long n,k,j,bien,l[100009],i,s,v=LONG_MIN;
struct q
{
    long long l;
    long long r;
    long long w;
};
q a[100009];
bool cmp(const q &x, const q &y)
{
    return x.r < y.r;
}
int main()
{
    freopen("FACILITY.INP","r",stdin);
    freopen("FACILITY.OUT","w",stdout);
    cin>>n>>k;
    for (i=1;i<=n;i++)
        cin>>a[i].l>>a[i].r>>a[i].w;
    for (i=1;i<=n;i++)
        a[i].r+=a[i].l;
    sort(a+1,a+1+n,cmp);
    for (i=1;i<=n;i++)
    {
        l[i]=a[i].w;
        for (j=1;j<i;j++)
        if (a[j].r  + k <= a[i].l && l[i]<l[j]+a[i].w)
            l[i]=l[j]+a[i].w;
    }
    for (i=1;i<=n;i++)
        v=max(v,l[i]);
    cout<<v;
    return 0;
}
