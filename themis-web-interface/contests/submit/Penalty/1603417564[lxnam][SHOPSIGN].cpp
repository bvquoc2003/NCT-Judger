#include <bits/stdc++.h>

using namespace std;
int n,i,j,dem,t;
long long a[1000005];
int main()
{
    freopen("SHOPSIGN.INP","r",stdin);
    freopen("SHOPSIGN.OUT","w",stdout);
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (i=1;i<=n;i++)
    {
        dem=1;
        for (j=i-1;j>=1;j--)
        {
            if (dem==a[i])
                break;
            if (a[j]>=a[i])
                dem++;
            else break;
        }
        for (j=i+1;j<=n;j++)
        {
            if (dem==a[i]) break;
            if (a[j]>=a[i])
                dem++;
            else break;
        }
        if (dem==a[i])
            t=max(t,dem);
    }
    printf("%d",t);
    return 0;
}
