#include <bits/stdc++.h>

using namespace std;
long long a[500005],t,u=100000000,b[500005],c[500005],x,y,d[500005],i,j,n,maxc;
int main()
{
    freopen("WRESTLING.INP","r",stdin);
    freopen("WRESTLING.OUT","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (i=1;i<=n;i++)
        cin>>b[i];
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
            if (b[i]==a[j])
        {
            x=i;
            y=j;
            break;
        }
        if (x>=y)
            c[i]=x-y;
        else{
            y=n-y;
            c[i]=x+y;
        }
        t=0;
        d[c[i]]++;
        if (d[c[i]]>=maxc)
        {
            maxc=d[c[i]];
            u=c[i];
        }
    }
    for (i=1;i<=n;i++)
        if (u==c[i])
    {
        u=c[i];
        break;
    }
    cout<<u<<" "<<maxc;
    return 0;
}
