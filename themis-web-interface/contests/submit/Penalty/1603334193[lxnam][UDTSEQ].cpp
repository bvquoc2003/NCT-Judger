#include <bits/stdc++.h>

using namespace std;
long long i,n,j,a[100010],x,y,z,m;
int main()
{
    freopen("UDTSEQ.INP","r",stdin);
    freopen("UDTSEQ.OUT","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&x,&y,&z);
        for (j=x;j<=y;j++)
            a[j]+=z;
    }
    for (i=1;i<=n;i++)
        printf("%lld",a[i]);
    return 0;
}
