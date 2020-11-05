#include <bits/stdc++.h>

using namespace std;
long long n,i,v,t,s,k;
map <int, int> a;
int main()
{
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    scanf("%lld%lld", &n, &k);
    for (i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        s=s+a[i];
    }
    v=k%s;
    if (v==0)
        printf("0");
    else {
        for (i=1;i<=n;i++)
            if (v>=a[i])
                v=v-a[i];
            else break;
        printf("%lld",v);
    }
    return 0;
}