#include <bits/stdc++.h>
using namespace std;

int n,m,u,v,k,a[100009];
int main()
{
    freopen("UDTSEQ.INP","r",stdin);
    freopen("UDTSEQ.OUT","w",stdout);
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        cin>>u>>v>>k;
        a[u]+=k;
        a[v+1]-=k;
    }
    for (int i=1;i<=n;i++)
        a[i]+=a[i-1];
    for (int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}
