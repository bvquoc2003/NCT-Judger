#include <bits/stdc++.h>
using namespace std;

long long n,m,u,v,i,k,a[100009];
int main()
{
    freopen("UDTSEQ.INP","r",stdin);
    freopen("UDTSEQ.OUT","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld",&u,&v,&k);
        a[u]+=k;
        a[v+1]-=k;
    }
    for (i=1;i<=n;i++)
        a[i]+=a[i-1];
    for (i=1;i<=n;i++)
        printf("%lld ",a[i]);
}
