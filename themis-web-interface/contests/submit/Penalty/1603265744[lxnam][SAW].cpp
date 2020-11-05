#include <bits/stdc++.h>

using namespace std;
int n,k,i,j,v,t,z,t_=10000009,a[100005],b[100005];
long long s,maxs=0,d[10000005];
int main()
{
    freopen("SAW.INP","r",stdin);
    freopen("SAW.OUT","w",stdout);
    scanf("%d%d",&n,&k);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        v=max(v,a[i]);
    }
    for (i=1;i<=k;i++)
    {
        scanf("%d",&b[i]);
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
        if (i==0)
            i=-1;
        d[s]=i;
        maxs=max(s,maxs);
    }
    for (i=1;i<=k;i++)
    {
        if (d[b[i]]==0)
        {
            for (j=b[i]+1;j<=maxs;j++)
                if (d[j]!=0)
            {
                if (d[j]!=-1)
                    printf("%lld ",d[j]);
                else printf("0 ");
                break;
            }
        }
        if (d[b[i]]!=0)
            printf("%lld ",d[b[i]]);
    }
    return 0;
}
