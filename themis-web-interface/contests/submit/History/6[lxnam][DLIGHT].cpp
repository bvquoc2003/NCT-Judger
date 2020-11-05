#include <bits/stdc++.h>

using namespace std;
long long q[10000009],a,b,dem,i,k,n;
int main()
{
    freopen("DLIGHT.INP","r",stdin);
    freopen("DLIGHT.OUT","w",stdout);
    cin>>n>>k;
    for (i=1;i<=k;i++)
    {
        cin>>a>>b;
        q[a]+=1;
        q[b+1]-=1;
    }
    for (i=1;i<=n;i++)
    {
        q[i]+=q[i-1];
        q[i]=q[i]%3;
        if (q[i]==0)
            dem++;
    }
    cout<<dem;
    return 0;
}
