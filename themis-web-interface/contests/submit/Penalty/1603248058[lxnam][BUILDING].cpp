#include <bits/stdc++.h>

using namespace std;
int s,n,m,i,j,s1,s2,s3,t,a[1009][1009];
int main()
{
    freopen("BUILDING.INP","r",stdin);
    freopen("BUILDING.OUT","w",stdout);
    scanf("%d%d", &n, &m);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        scanf("%d", &a[i][j]);
    s=0;s1=0;s2=0;s3=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
    {
        if (a[i][j]-a[i+1][j]>0)
            s=1;
        if (a[i][j]-a[i-1][j]>0)
            s1=1;
        if (a[i][j]-a[i][j+1]>0)
            s2=1;
        if (a[i][j]-a[i][j-1]>0)
            s3=1;
        if (s==0 && s1==0 && s2==0 && s3==0)
            t++;
        s=0;s1=0;s2=0;s3=0;
    }
    printf("%d", t);
    return 0;
}
