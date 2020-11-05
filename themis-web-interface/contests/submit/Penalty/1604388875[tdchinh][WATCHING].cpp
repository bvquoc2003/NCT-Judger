#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,m,t,k,a[100005],b[100005],x,na,nb,sa,sb;
long long c[100005],d[100005],z;
int main()
{
    FastIO;
    freopen("WATCHING.INP","r",stdin);
    freopen("WATCHING.OUT","w",stdout);
    cin >> n >> m >> t >> k;
    a[n+1] = t;
    b[m+1] = t;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i > 1)
            c[i] = a[i] - a[i-1] - k;
            else
                c[i] = a[i];
        }
    for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
            if (i > 1)
            d[i] = b[i] - b[i-1] - k;
            else
                d[i] = b[i];
        }
    n++;
    m++;
    c[n] = a[n] - a[n-1] - k;
    d[m] = b[m] - b[m-1] - k;
    x = 0;
    na = 1;
    nb = 1;
    z = 1;
    while (x <= t)
    {
        if (z == 1)
        {
            if (a[na] > t)
            {
               sa = sa + min(a[na]-x,c[na]) - a[na]-t+1;
               z = 3;
            }
            if (a[na] == t)
            {
                sa = sa + min(a[na]-x,c[na]);
                z = 3;
            }
            if (z == 3)
            {
                cout << sa << " " << sb;
                exit(0);
            }
            if (na > 1)
            while (a[na] <= x)
            {
                na++;
            }
            if (c[na] >= 0)
            {
            sa = sa + min(a[na]-x,c[na]);
            z = 2;
            }
            x = a[na];
            na++;
        }
        if (z == 2)
        {
            if (b[nb] > t)
            {
               sb = sb + min(b[nb]-x,d[nb]); - b[nb]-t+1;
               z = 3;
            }
            if (b[nb] == t)
            {
                sb = sb + min(b[nb]-x,d[nb]);
                z = 3;
            }
            if (z == 3)
            {
                cout << sa << " " << sb;
                exit(0);
            }
            while (b[nb] <= x)
            {
                nb++;
            }
            if (d[nb] >= 0)
            {
            sb = sb + min(b[nb]-x,d[nb]);
            z = 1;
            }
            x = b[nb];
            nb++;
        }
        if (t == x)
            break;
    }
    cout << sa << " " << sb;
    return 0;
}
