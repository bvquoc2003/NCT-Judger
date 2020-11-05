#include <bits/stdc++.h>

using namespace std;
int n,k,i,j;
long long s,d[10000005],maxs,v,z,t,t_=1000000000000009,a[100005],b[100005];
int main()
{
    freopen("SAW.INP","r",stdin);
    freopen("SAW.OUT","w",stdout);
    scanf("%d%d",&n,&k);
    for (i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        v=max(v,a[i]);
    }
    for (i=1;i<=k;i++)
    {
        scanf("%lld",&b[i]);
        t=max(t,b[i]);
        t_=min(t_,b[i]);
    }
    sort(a+1,a+1+n);
    z=v-t;
    if (v-t<0)
        z=0;
    for (i=v;i>=z;i--)
    {
        s=0;
        for (j=n;j>=1;j--)
            if (a[j]-i>0)
                s+=(a[j]-i);
            else break;
        d[s]=i;
        if (i==0)
            d[s]=-1;
        maxs=max(maxs,s);
    }
    for (i=1;i<=k;i++)
    {
        if (d[b[i]]==0)
            for (j=b[i]+1;j<=maxs;j++)
                if (d[j]!=0)
            {
                if (d[j]!=-1)
                    printf("%lld ",d[j]);
                else printf("0 ");
                break;
            }
        if (d[b[i]]!=0)
            if (d[b[i]]!=-1)
                printf("%lld ",d[b[i]]);
            else printf("0 ");
    }
    return 0;
}
