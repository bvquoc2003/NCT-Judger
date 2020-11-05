#include <bits/stdc++.h>

using namespace std;
int n,i,j,a[100005],q[100005];
long long S,minc,s,t,v;
int main()
{
    freopen("LEAVES.INP","r",stdin);
    freopen("LEAVES.OUT","w",stdout);
    scanf("%d%lld",&n,&S);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (i=1;i<=n;i++)
    {
        minc=100000000000000;
        for (j=1;j<=n;j++)
        {
            s=a[j]+j*i;
            q[j]=s;
        }
        t=0;
        sort (q+1,q+1+n);
        for (j=1;j<=i;j++)
            t+=q[j];
        if (t>S)
        {
            i--;
            break;
        }
        if (t==S)
            break;
        v=t;
    }
    if (i!=0)
        printf("%d %lld",i,v);
    else printf("0");
    return 0;
}
