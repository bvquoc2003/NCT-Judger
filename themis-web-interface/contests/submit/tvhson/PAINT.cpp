#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e3 + 5;
long long n, m, a[maxn][maxn];
long long s = 0;

int32_t main()
{
    freopen("PAINT.INP", "r", stdin);
    freopen("PAINT.OUT", "w", stdout);
    scanf("%lld%lld", &m ,&n);
    for(int i = 0; i < m+2; i++)
        for(int j = 0; j < n+2; j++)
        {
            if(i == 0 || i == m+1 || j == 0 || j == n+1) a[i][j] = 0;
            else
            {
                scanf("%lld", &a[i][j]);
                if(a[i][j] > 0) s++;
            }
        }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(a[i][j] > a[i-1][j])
                s += a[i][j] - a[i-1][j];
            if(a[i][j] > a[i+1][j])
                s += a[i][j] - a[i+1][j];
            if(a[i][j] > a[i][j-1])
                s += a[i][j] - a[i][j-1];
            if(a[i][j] > a[i][j+1])
                s += a[i][j] - a[i][j+1];
        }
    }
    printf("%lld", s);
}
