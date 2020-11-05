#include <bits/stdc++.h>

using namespace std;
long long s,v,vv,n,m,i,ss,tt,k,dem,j,maxc,minc=1000005,t,w[100005],d[100005],p[100005];
int main()
{
    freopen("TALENT.INP","r",stdin);
    freopen("TALENT.OUT","w",stdout);
    scanf("%lld%lld", &n, &m);
    for (i=1;i<=n;i++)
    {
        scanf("%lld", &d[i]);
        if (d[i]>maxc)
            maxc=d[i];
        if (d[i]<minc)
            minc=d[i];
    }
    for (i=1;i<=n;i++)
    {
        scanf("%lld", &w[i]);
        if (w[i]==1)
            dem++;
    }
    for (i=1;i<=m;i++)
        scanf("%lld", &p[i]);
    if (dem!=n){
        s=0;
        for (k=1;k<=m;k++)
        {
            for (i=1;i<=n;i++)
                s=s+w[i]*abs(d[i]-p[k]);
            printf("%lld\n",s);
            s=0;
        }
    }
    else {
        for (i=1;i<=n;i++)
            s=s+abs(d[i]-maxc);
        v=s;
        for (i=1;i<=n;i++)
            ss=ss+abs(d[i]-minc);
        vv=ss;
        for (i=1;i<=m;i++)
        {
            s=0;
            ss=0;
            if (p[i]==maxc)
                printf("%lld\n",v);
            if (p[i]>maxc)
            {
                t=p[i]-maxc;
                s=s+t*n+v;
                printf("%lld\n",s);
            }
            if (p[i]<maxc && p[i]>minc)
            {
                for (j=1;j<=n;j++)
                    s=s+abs(d[j]-p[i]);
                printf("%lld\n",s);
            }
            if (p[i]==minc)
                printf("%lld\n",vv);
            if (p[i]<minc)
            {
                tt=minc-p[i];
                s=s+tt*n+vv;
                printf("%lld\n",s);
            }
        }
    }
    return 0;
}
