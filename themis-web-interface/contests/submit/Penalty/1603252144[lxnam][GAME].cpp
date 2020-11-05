#include <bits/stdc++.h>

using namespace std;
int i,j,c[100005],res,n,bien;
long long a[100006],s,v,t=LONG_MAX,b[100006];
int tknp(long long a[],long long l,long long r,long long x)
{
    while (l<=r)
    {
        res=(l+r)/2;
        if (a[res]==x)
            return res;
        if (a[res]>x)
            r=res-1;
        if (a[res]<x)
            l=res+1;
    }
    return 0;
}
int main()
{
    freopen("GAME.INP","r",stdin);
    freopen("GAME.OUT","w",stdout);
    scanf("%d", &n);
    for (i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    t=LONG_MAX;v=LONG_MAX;
    for (i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);
        tknp(a,1,n,-b[i]);
        if (a[res]==-b[i])
        {
            printf("0");
            bien=1;
            break;
        }
        s=a[res+1]+b[i];
        v=min(s,a[res]+b[i]);
        if (res-1>1)
            v=min(v,a[res-1]+b[i]);
        t=min(t,v);
    }
    if (bien==0) printf("%lld",t);
    return 0;
}
