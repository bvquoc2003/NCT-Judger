#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
unsigned long long n,m,t,k,a[100005],b[100005],x,na,nb,sa,sb;
unsigned long long c[100005],d[100005],z;
int main()
{
    FastIO;
    freopen("WATCHING.INP","r",stdin);
    freopen("WATCHING.OUT","w",stdout);
    cin >> n >> m >> t >> k;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i > 1)
            c[i] = a[i] - a[i-1] - k;
            else
                c[i] = a[i] - 1;
        }
    for (int i = 1; i <= m; i++)
        {
            cin >> b[i];
            if (i > 1)
            d[i] = b[i] - b[i-1] - k;
            else
                d[i] = b[i] - 1;
        }
    x = 1;
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
                sb++;
                z = 3;
            }
            if (z == 3)
            {
                cout << sa << " " << sb;
                exit(0);
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
                sa++;
                z = 3;
            }
            if (z == 3)
            {
                cout << sa << " " << sb;
                exit(0);
            }
            if (d[nb] >= 0)
            {
            sb = sb + min(b[nb]-x,d[nb]);
            z = 1;
            }
            x = b[nb];
            nb++;
        }
        if (na > n && nb > m)
            break;

    }
    cout << sa << " " << sb;
    return 0;
}
