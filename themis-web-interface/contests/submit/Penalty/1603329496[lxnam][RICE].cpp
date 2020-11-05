#include <bits/stdc++.h>

using namespace std;
long long i,s,minc=1000000000004,h,b[100005],x,a[100005],n;
int main()
{
    freopen("RICE.INP","r",stdin);
    freopen("RICE.OUT","w",stdout);
    scanf("%lld", &n);
    for (i=1;i<=n;i++)
    {
        scanf("%lld%lld", &a[i], &b[i]);
        s+=b[i];
        minc=min(b[i],minc);
    }
    h=a[n]-a[1];
    s=s-h;
    s=s/n;
    if (s>0)
        printf("%lld",s);
    else printf("%lld",minc);
    return 0;
}
