#include <bits/stdc++.h>

using namespace std;
long long a[1006][1006],s;
long long i, j, n, m;
int main()
{
    //ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    scanf("%lld%lld", &n, &m);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
    {
        scanf("%lld", &a[i][j]);
        if (a[i][j]>0)
            s++;
    }
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
    {
        if (a[i][j]-a[i+1][j]>0)
            s+=a[i][j]-a[i+1][j];
        if (a[i][j]-a[i-1][j]>0)
            s+=a[i][j]-a[i-1][j];
        if (a[i][j]-a[i][j+1]>0)
            s+=a[i][j]-a[i][j+1];
        if (a[i][j]-a[i][j-1]>0)
            s+=a[i][j]-a[i][j-1];
    }

    printf("%lld", s);
    return 0;
}
