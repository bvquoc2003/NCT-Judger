#include <bits/stdc++.h>

using namespace std;
long long i,k,v,s,n,s_a[100009],a[100009],m;
int tknp(long long l,long long r)
{
    long long res=0,x=LONG_MAX,mid;
    while (l<=r)
    {
        x=LONG_MAX;
        res=(l+r)/2;
        for (i=res;i<=n;i++)
            x=min(x,s_a[i]-s_a[i-res]);
        if (x>=m)
        {
            mid=res;
            r=res-1;
        }
        else l=res+1;
    }
    return mid;
}
int main()
{
    freopen("TANK.INP","r",stdin);
    freopen("TANK.OUT","w",stdout);
    cin>>m>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        s_a[i]=s_a[i-1]+a[i];
    }
    cout<<tknp(1,n);
    return 0;
}
