#include <bits/stdc++.h>
using namespace std;

int n,m,q;
vector<int> a;
int res;
void input()
{
    cin>>n>>m;
    a.resize(n+9);
    for (int i=0;i<m;i++)
    {
        int u,v,k;
        cin>>u>>v>>k;
        a[u]+=k;
        a[v+1]-=k;
    }
    for (int i=1;i<=n;i++)
        a[i]+=a[i-1];
}
int main()
{
    freopen("UDTSEQ.INP","r",stdin);
    freopen("UDTSEQ.OUT","w",stdout);
    input();
    for (int i=1;i<=n;i++)
        cout<<a[i]<<" ";
}
