#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,m,x[100001],c[100001],g[100001],minz[100001],f[100001];
int main()
{
    FastIO;
    freopen("MARKET.INP","r",stdin);
    freopen("MARKET.OUT","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= m; i++)
        cin >> c[i];
    minz[m] = c[m];
    for (int i = m-1; i >= 1; i--)
    {
        if (c[i] < minz[i+1])
            minz[i] = c[i];
        else
            minz[i] = minz[i+1];
    }
    sort(x+1,x+n+1);
    for (int i = 1; i <= m; i++)
        f[i] = 1000000000;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            f[i] = min(f[i],f[j]+minz[x[i]-x[j+1]+1]);
        }
    }
    cout << f[n];
    return 0;
}
