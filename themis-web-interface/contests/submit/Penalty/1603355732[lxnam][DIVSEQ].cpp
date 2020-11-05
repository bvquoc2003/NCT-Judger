#include <bits/stdc++.h>

using namespace std;

long long a[50005],s_a[50005],res;
int n,i,d,t,j,k;
int main()
{
    freopen("DIVSEQ.INP","r",stdin);
    freopen("DIVSEQ.OUT","w",stdout);
    scanf("%d",&t);
    for (k=1;k<=t;k++){
    scanf("%d%d", &d, &n);
    for (i=1; i<=n; i++) {
        scanf("%lld", &a[i]);
        s_a[i]=s_a[i-1]+a[i];
    }
    res=0;
    for (i=1;i<=n;i++) {
        for (j=i;j<=n;j++) {
            if ((s_a[j]-s_a[i-1])%d==0)
                res++;
        }
    }
    printf("%lld\n", res);
    }
}
