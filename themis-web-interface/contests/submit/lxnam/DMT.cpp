#include <bits/stdc++.h>

using namespace std;
long long b,d,j,i,z,h,k,t,n,a[333349];
int main()
{
    freopen("DMT.INP","r",stdin);
    freopen("DMT.OUT","w",stdout);
    n=333340;
    for (i=1;i<=n;i++)
        a[i]=1;
    for (i=2;i*i<=n;i++)
        if (a[i]==1)
            for (j=i*i;j<=n;j+=i)
                a[j]=0;
    scanf("%lld", &t);
    for (k=1;k<=t;k++)
    {
        z=0;
        scanf("%lld%lld", &b , &d);
        for (i=2;i<=n;i++)
            if (a[i]==1 && i!=3)
        {
            h=i*i*9;
            if (h>=b && h<=d)
                z++;
            if (h>d)
            {
                printf("%lld\n",z);
                break;
            }
        }
    }
    return 0;
}
