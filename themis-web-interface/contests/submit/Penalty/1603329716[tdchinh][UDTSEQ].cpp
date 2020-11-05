#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,m,u,v,w,a[100001];
int main()
{
    FastIO;
    freopen("UDTSEQ.INP","r",stdin);
    freopen("UDTSEQ.OUT","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld",&u,&v,&w);
        for (int j = u; j <= v; j++)
            a[j] = a[j] + w;
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ",a[i]);
    return 0;
}
