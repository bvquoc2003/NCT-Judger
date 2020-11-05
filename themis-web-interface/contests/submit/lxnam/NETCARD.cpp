#include <bits/stdc++.h>

using namespace std;
int n,k,a[100005],b[100005],v[100005],d[100005],i,h[100004],kt[100004];
int main()
{
    freopen("NETCARD.INP","r",stdin);
    freopen("NETCARD.OUT","w",stdout);
    cin>>n>>k;
    for (i=1;i<=n;i++)
        d[i]=2;

    for (i=1;i<=k;i++)
    {
        cin>>a[i]>>b[i]>>v[i];
        if (v[i]==1)
        {
            d[a[i]]=1;
            d[b[i]]=1;
        }
    }
    for (i=1;i<=k;i++)
    {
        if (v[i]==0 && d[a[i]]==1)
            d[b[i]]=0;
        if (v[i]==0 && d[b[i]]==1)
            d[a[i]]=0;
    }
    for (i=1;i<=n;i++)
        cout<<d[i]<<" ";
    return 0;
}
