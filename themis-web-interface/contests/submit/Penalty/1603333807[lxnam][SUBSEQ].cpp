#include <bits/stdc++.h>

using namespace std;
long long i,n,j,b[1010],d,d1,c[1010],kt[1010],a[1010],s,t,k,dem;
int main()
{
    freopen("SUBSEQ.INP","r",stdin);
    freopen("SUBSEQ.OUT","w",stdout);
    scanf("%lld",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=a[i];
        s+=a[i];
    }
    t=s;
    s/=2;
    sort(a+1,a+1+n);
    for (i=n;i>=1;i--)
    {
        t-=a[i];
        if (t>s)
        {
            kt[i]=1;
            for (j=1;j<=n;j++)
            {
                if (t-a[j]<=s && kt[j]==0)
                    d++;
                if (kt[j]==0)
                    d1++;
            }
            if (d==d1)
            {
                break;
            }
            d=0;d1=0;
        }
        else
            t+=a[i];
    }
    printf("%lld\n",d1);
    for (i=1;i<=n;i++)
        if (kt[i]==0)
            for (j=1;j<=n;j++)
                if (a[i]==b[j] && b[j]!=-1)
        {
            printf("%lld ",j);
            b[j]=-1;
        }
    return 0;
}
