#include <bits/stdc++.h>

using namespace std;
int s,n,m,i,j,s1,t,u,s2,s3,a[1009][1009],maxc=0;
int main()
{
    freopen("BUILDING.INP","r",stdin);
    freopen("BUILDING.OUT","w",stdout);
    scanf("%d%d", &n, &m);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        scanf("%d", &a[i][j]);
    s=0;s1=0;
    t=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
    {
        for (u=j+1;u<=m;u++)
            if (a[i][u]>a[i][j])
            {
                s=1;break;
            }
        for (u=j-1;u>=1;u--)
            if (a[i][u]>a[i][j])
            {
                s1=1;break;
            }
        for (u=i-1;u>=1;u--)
            if (a[u][j]>a[i][j])
            {
                s2=1;break;
            }
        for (u=i+1;u<=n;u++)
            if (a[u][j]>a[i][j])
            {
                s3=1;break;
            }
        if (s1==1 && s==1 && s2==1 && s3==1)
            if (i!=1 && i!=n && j!=1 && j!=m)
                t++;
        s=0;s1=0;s2=0;s3=0;
    }
    printf("%d", t);
    return 0;
}
