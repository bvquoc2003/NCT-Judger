#include <bits/stdc++.h>

using namespace std;
long long n,m,x[100001],c[100001],g[100001],d[100001],f[100001];
int main()
{
    freopen("MARKET.INP","r",stdin);
    freopen("MARKET.OUT","w",stdout);
    cin>>n>>m;
    for (i=1;i<=n;i++)
        cin>>x[i];
    for (i=1;i<=m;i++)
        cin>>c[i];
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
    cout<<f[n];
    return 0;
}
