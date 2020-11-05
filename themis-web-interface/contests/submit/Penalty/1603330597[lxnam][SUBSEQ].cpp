#include <bits/stdc++.h>

using namespace std;
long long i,j,n,b[1010],c[1010],q[1010],a[1010],s,t,k,dem;
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
    s/=2;
    sort(a+1,a+1+n);
    for (i=n;i>=1;i--)
    {
        t+=a[i];
        if (t-a[i]<=s)
        {
            dem++;
            k++;
            q[k]=a[i];
        }
    }
    for (i=1;i<=k;i++)
        for (j=1;j<=n;j++)
        if (q[i]==b[j] && b[j]!=-1)
        {
            c[i]=j;
            b[j]=-1;
        }
    sort(c+1,c+1+k);
    printf("%lld\n",dem);
    for (i=1;i<=k;i++)
        printf("%lld ",c[i]);
    return 0;
}
