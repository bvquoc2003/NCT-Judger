#include <bits/stdc++.h>

using namespace std;
long long i,s,j,minc=1000000000004,h,b[100005],c[100005],a[100005],n,x;
int main()
{
    freopen("RICE.INP","r",stdin);
    freopen("RICE.OUT","w",stdout);
    scanf("%lld", &n);
    for (i=1;i<=n;i++)
    {
        scanf("%lld%lld", &a[i], &b[i]);
        s+=b[i];
    }
    s=s/n;
    while (s>0){
    minc=10000000000004;
    for (i=1;i<=n;i++)
        c[i]=b[i];x=0;
    for (i=1;i<=n;i++)
    {
        if (c[i]>s)
        {
            if (x!=0 && x<i)
            {
                h=c[i]-abs(a[i]-a[x])-(s-c[x]);
                if (h<0)
                    h=0;
                else c[i]=h;
                c[x]=s;
            }
            else {
                h=c[i]-s-abs(a[i]-a[i+1]);
                if (h<0)
                    h=0;
                c[i+1]=c[i+1]+h;
                c[i]=s;
            }
        }
        if (c[i]<s)
            x=i;
    }
    for (i=1;i<=n;i++)
        if (c[i]<s)
            for (j=1;j<=n;j++)
            if (c[j]>s)
            {
                c[i]+=c[j]-s-abs(a[i]-a[j]);
                c[j]=s;
                if (c[i]>=s)
                    break;
            }
    for (i=1;i<=n;i++)
        if (c[i]<minc)
        minc=c[i];
    if (minc==s)
        break;
    s--;
    }
    printf("%lld",minc);
    return 0;
}
