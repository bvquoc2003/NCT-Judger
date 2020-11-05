#include <bits/stdc++.h>

using namespace std;
long long n,m,i,k,minc,x[100001],c[100001],g[100001],d[100001],f[100001];
int main()
{
    freopen("MARKET.INP","r",stdin);
    freopen("MARKET.OUT","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (i=1;i<=n;i++)
        scanf("%lld",&x[i]);
    for (i=1;i<=m;i++)
        scanf("%lld",&c[i]);
    minc=10000000000000;
    sort(x+1,x+1+n);
    f[0]=0;
    for (i=m;i>=1;i--)
    {
        d[i]=min(minc,c[i]);
        minc=min(minc,c[i]);
        f[i]=INT_MAX;
    }
    for (i=1;i<=n;i++)
    {
        for (k=0;k<i;k++)
            f[i]=min(f[i],f[k]+d[x[i]-x[k+1]+1]);
    }
    printf("%lld",d[n]);
    return 0;
}
