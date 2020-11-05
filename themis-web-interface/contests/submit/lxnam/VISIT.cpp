#include <bits/stdc++.h>

using namespace std;

long long a[200005],b[200005],res,x[200005],y[200005];
int n,i,j;
int main()
{
    freopen("VISIT.INP","r",stdin);
    freopen("VISIT.OUT","w",stdout);
    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    x[0]=1;y[0]=1;
    for (i=1;i<=n;i++)
    {
        y[i]=min(x[i-1]+b[i]-a[i]+abs(a[i-1]-a[i]),y[i-1]+b[i]-a[i]+abs(b[i-1]-a[i]));
        x[i]=min(x[i-1]+b[i]-a[i]+abs(a[i-1]-b[i]),y[i-1]+b[i]-a[i]+abs(b[i-1]-b[i]));
    }
    res=min(n-a[n]+x[n],n-b[n]+y[n])+n-1-2;
    printf("%lld\n", res);
    return 0;
}
