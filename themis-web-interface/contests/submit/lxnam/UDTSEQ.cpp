#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int n,m,u,v,i,k,a[100009];
int main()
{
    FastIO;
    freopen("UDTSEQ.INP","r",stdin);
    freopen("UDTSEQ.OUT","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d",&u,&v,&k);
        a[u]+=k;
        a[v+1]-=k;
    }
    for (i=1;i<=n;i++)
        a[i]+=a[i-1];
    for (i=1;i<=n;i++)
        printf("%d ",a[i]);
}
