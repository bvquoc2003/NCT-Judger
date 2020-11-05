#include <bits/stdc++.h>

using namespace std;
int n,i,j,a[100005],q[100005];
long long S,s,t,v,k,l,r;
int main()
{
    freopen("LEAVES.INP","r",stdin);
    freopen("LEAVES.OUT","w",stdout);
    scanf("%d%lld",&n,&S);
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]);
    l=1;r=n;
    while (l<=r){
        i=(r+l)/2;
        for (j=1;j<=n;j++)
        {
            s=a[j]+j*i;
            q[j]=s;
        }
        t=0;
        sort (q+1,q+1+n);
        for (j=1;j<=i;j++)
            t+=q[j];
        if (t<=S)
        {
            k=i;
            v=t;
            l=i+1;
        }
        else r=i-1;
    }
    if (k!=0)
        printf("%d %lld",k,v);
    else printf("0");
    return 0;
}
