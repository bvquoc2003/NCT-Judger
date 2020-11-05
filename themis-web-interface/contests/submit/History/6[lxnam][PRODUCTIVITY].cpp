#include <bits/stdc++.h>

using namespace std;
long long i,j,a[1009][1009],minb,maxb,u,k[1009],n,v,h,b[1009];
int main()
{
    freopen("PRODUCTIVITY.INP","r",stdin);
    freopen("PRODUCTIVITY.OUT","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        cin>>a[i][j];
    v=LONG_MAX;
    for (i=1;i<=n;i++)
    {
        h=0;
        for (j=1;j<=n;j++)
            h=max(a[j][i],h);
        k[i]=h;
        v=min(v,h);
    }
    for (u=v;u>=0;u--)
    {
        maxb=0;
        minb=LONG_MAX;
        for (i=1;i<=n;i++)
            b[i]=0;
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
                if (a[i][j]>=u)
                    b[j]++;
        for (i=1;i<=n;i++)
        {
            maxb=max(maxb,b[i]);
            minb=min(minb,b[i]);
        }
        if (maxb==1)
        {
            cout<<u;
            break;
        }
        else {
            if (minb==2)
            {
                cout<<u;
                return 0;
            }
        }
    }
    return 0;
}
