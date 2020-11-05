#include <bits/stdc++.h>

using namespace std;
int n,k,a,b,v,d[100005],i,h[100004],kt[100004];
int main()
{
    freopen("NETCARD.INP","r",stdin);
    freopen("NETCARD.OUT","w",stdout);
    cin>>n>>k;
    for (i=1;i<=n;i++)
        d[i]=2;
    for (i=1;i<=k;i++)
    {
        cin>>a>>b>>v;
        if (v==1)
        {
            d[a]=1;
            d[b]=1;
            kt[a]=1;kt[b]=1;
            d[h[a]]=0;
            d[h[b]]=0;
        }
        if (v==0 && d[a]==1)
        {
            if (kt[b]==0)
            {
                d[b]=0;
                kt[b]=1;
            }
        }
        if (v==0 && d[b]==1)
        {
            if (kt[a]==0)
            {
                d[a]=0;
                kt[a]=1;
            }
        }
        if (v==0 && d[a]==2 && d[b]==2)
        {
            h[a]=b;
            h[b]=a;
        }
    }
    for (i=1;i<=n;i++)
        cout<<d[i]<<" ";
    return 0;
}
