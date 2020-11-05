#include <bits/stdc++.h>

using namespace std;
long long i,k,v,s,n,a[100009],m;
int main()
{
    freopen("TANK.INP","r",stdin);
    freopen("TANK.OUT","w",stdout);
    cin>>m>>n;
    for (i=1;i<=n;i++)
        cin>>a[i];
    for (i=1;i<=n;i++)
    {
        s+=a[i];
        if (s>=m)
        {
            v=i;
            k=i;
            break;
        }
    }
    for (i=v+1;i<=n;i++)
    {
        s-=a[i-v];
        s+=a[i];
        if (s<m)
        {
            k++;
            s+=a[i-v+1];
        }
    }
    cout<<k;
    return 0;
}
