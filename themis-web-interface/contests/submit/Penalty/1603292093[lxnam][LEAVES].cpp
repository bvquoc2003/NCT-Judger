#include <bits/stdc++.h>

using namespace std;
int n,i,j,k,a[100005];
long long S,minc,s,t,v;
int main()
{
    freopen("LEAVES.INP","r",stdin);
    freopen("LEAVES.OUT","w",stdout);
    scanf("%d%lld",&n,&S);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    k=100005;
    for (i=1;i<=k;i++)
    {
        minc=100000000000000;
        for (j=1;j<=n;j++)
        if (a[j]+j*i<minc && a[j]!=0)
        {
            minc=a[j]+j*i;
            v=j;
        }
        a[v]=0;
        t=t+s+minc;
        if (t>S)
        {
            t=t-s-minc;
            i--;
            break;
        }
        s+=v;
    }
    if (i!=0)
        printf("%d %lld",i,t);
    else printf("0");
    return 0;
}
