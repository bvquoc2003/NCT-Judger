#include <bits/stdc++.h>

using namespace std;

long long a[1005],d[1009], b[1005],s_a[1005], s_b[1005],res;
int n,m,i,j;
int main()
{
    freopen("SEQPAIRS.INP","r",stdin);
    freopen("SEQPAIRS.OUT","w",stdout);
    scanf("%d%d", &n, &m);
    for (i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
        s_a[i]=s_a[i-1]+a[i];
    }
    for (i=1; i<=m; i++) {
        scanf("%lld", &b[i]);
        s_b[i]=s_b[i-1]+b[i];
    }
    for (i=1;i<=n;i++) {
        for (j=i;j<=n;j++) {
            d[s_a[j]-s_a[i-1]]++;
        }
    }
    res=0;
    for (i=1;i<=m;i++) {
        for (j=i;j<=m;j++) {
            res+=d[s_b[j]-s_b[i-1]];
        }
    }
    printf("%lld", res);
}