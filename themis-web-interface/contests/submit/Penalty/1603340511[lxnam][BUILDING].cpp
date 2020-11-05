#include <bits/stdc++.h>

using namespace std;
int n,m,i,j,dem,mt,a[1009][1009],t[1009][1009],p[1009][1009],tr[1009][1009],d[1009][1009];
int main()
{
    freopen("BUILDING.INP","r",stdin);
    freopen("BUILDING.OUT","w",stdout);
    scanf("%d%d", &n, &m);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            scanf("%d", &a[i][j]);
    for (i=1;i<=n;i++)
    {
        mt=0;
        for (j=1;j<=m;j++)
        {
            if (a[i][j]<mt)
                t[i][j]=1;
            mt=max(mt,a[i][j]);
        }
        mt=0;
        for (j=m;j>=1;j--)
        {
            if (a[i][j]<mt)
                p[i][j]=1;
            mt=max(mt,a[i][j]);
        }
    }
    for (i=1;i<=n;i++)
    {
        mt=0;
        for (j=1;j<=m;j++)
        {
            if (a[j][i]<mt)
                tr[j][i]=1;
            mt=max(mt,a[j][i]);
        }
        mt=0;
        for (j=m;j>=1;j--)
        {
            if (a[j][i]<mt)
                d[j][i]=1;
            mt=max(mt,a[j][i]);
        }
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (t[i][j]==1 && tr[i][j]==1 && p[i][j]==1 && d[i][j]==1)
                dem++;
    printf("%d", dem);
    return 0;
}
