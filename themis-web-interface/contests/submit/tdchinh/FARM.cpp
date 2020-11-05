#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,k,q,p,a[10004],l[10004],z,dem[10004],minz[10004],u,maxc;
int main()
{
    FastIO;
    freopen("FARM.INP","r",stdin);
    freopen("FARM.OUT","w",stdout);
    cin >> n >> k >> q >> p;
    for (int i = 1 ; i <= n; i++)
        cin >> a[i];
    if (q % p ==0)
        z = q/p;
    else
        z = q/p+1;
    for (int i = 1; i <= n; i++)
    {
        l[i] = a[i]*p;
        dem[i] = 1;
        minz[i] = a[i];
        for (int j = 1; j < i; j++)
        {
            if (i-j >= k && 1 + dem[j] <= z && l[i] < l[j] + p*a[i])
            {
                l[i] = l[j] + a[i]*p;
                dem[i] = 1 + dem[j];
                u = j;
            }
        }
        if (u != 0)
        minz[i] = min(minz[i],minz[u]);

    }
    for (int i = 1; i <= n; i++)
    {
        if (dem[i] == z)
        {
            l[i] = l[i] - (z*p-q)*minz[i];
        }
    }
    for (int i = 1; i <= n; i++)
        if (maxc < l[i])
            maxc = l[i];
    cout << maxc;
    return 0;
}
