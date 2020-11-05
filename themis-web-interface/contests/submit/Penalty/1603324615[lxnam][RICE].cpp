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
    for (i=1;i<=n;i++)
        c[i]=b[i];x=0;
    for (i=1;i<=n;i++)
        if (c[i]<s)
        {
            for (j=1;j<=i-1;j++)
            {
                if (c[i]>=s) break;
                if ((c[j]-s)-abs(a[i]-a[j])>0)
                    c[i]+=(c[j]-s)-abs(a[i]-a[j]);
                c[j]=s;
            }
            for (j=i+1;j<=n;j++)
            {
                if (c[i]>=s) break;
                if (c[j]>s)
                    if ((c[j]-s)-abs(a[i]-a[j])>0)
                        c[i]+=(c[j]-s)-abs(a[i]-a[j]);
                c[j]=s;
            }
        }
        minc=10000000000004;
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
