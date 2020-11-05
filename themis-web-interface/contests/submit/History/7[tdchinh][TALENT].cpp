#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(0) ; cout.tie(0);
#define ft first
#define sc second
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define endl '\n'
using namespace std;
const int N = 100001;
long long n,m,d[N],w[N],p[N],f[N],dcl[N],t,khoang[N],p1,k[N];
int main()
{
    FastIO;
    freopen("TALENT.INP","r",stdin);
    freopen("TALENT.OUT","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
        for (int i = 1 ; i <= m; i++)
    {
        cin >> p[i];
    }
    if (n <= 100000 && m <= 10)
    {
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[j] = f[j] + w[i]*abs(d[i]-p[j]);
        }
    }
    for (int i = 1; i <= m; i++)
        cout << f[i] << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            t = t - w[i];
        }
        for (int i = d[0]+1; i <= d[1]; i++)
            dcl[i] = t;
        for (int i = 2; i <= n; i++)
        {
            for (int j = d[i-1] + 1; j <= d[i]; j++)
            {
                dcl[j] = t+w[i-1]*2;
            }
                            t = t+w[i-1]*2;
        }
    for (int i = d[n]; i <= 100000; i++)
        dcl[i] = abs(dcl[1]);
    for (int i = 1; i <= n; i++)
    {
        p1 = p1 + w[i] * abs(d[i] - 1);
    }
    for (int i = 2; i <= 100000; i++)
    {
        k[i] = abs(p1 + dcl[i]);
        p1 = k[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cout << k[p[i]] << endl;
    }
    }
    return 0;
}