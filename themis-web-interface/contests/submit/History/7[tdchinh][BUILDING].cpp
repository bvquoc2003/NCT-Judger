#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr) ; cout.tie(nullptr)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define endl "\n"
using namespace std;
int n,m,a[1001][1001],s,maxp[1001],maxd[1001],maxpa[1001],maxda[1001],maxa[1001],maxt[1001];
void thuchien(int i, int j)
{
    if (j == maxpa[i])
                {
                    maxp[i] = 0;
                    for (int k = j+1; k <= m; k++)
                    {
                        if (maxp[i] < a[i][k])
                        {
                            maxp[i] = a[i][k];
                            maxpa[i] = k;
                        }
                    }
                }
            if (i == maxda[j])
                {
                    maxd[j] = 0;
                    for (int k = i+1; k <= n; k++)
                     {
                         if (maxd[j] < a[k][j])
                         {
                             maxd[j] = a[k][j];
                             maxda[j] = k;
                         }
                     }
                }
}
int main()
{
    FastIO;
    freopen("BUILDING.INP","r",stdin);
    freopen("BUILDING.OUT","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                 scanf("%d",&a[i][j]);
    for (int i = 2;i < n; i++)
    {
        for (int j = 3; j <= m; j++)
        {
            if (maxp[i] <= a[i][j])
            {
                maxp[i] = a[i][j];
                maxpa[i] = j;
            }
        }
    }
    for (int i = 2;i < m; i++)
    {
        for (int j = 3; j <= n; j++)
        {
            if (maxd[i] <= a[j][i])
            {
                maxd[i] = a[j][i];
                maxda[i] = j;
            }
        }
    }
    for (int i = 2; i < m; i++)
    {
        maxt[i] = a[1][i];
    }
    for (int i = 2; i < n; i++)
    {
        maxa[i] = a[i][1];
    }
    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < m; j++)
        {
            thuchien(i,j);
            if (a[i][j] < maxa[i] && a[i][j] < maxt[j] && a[i][j] < maxp[i] && a[i][j] < maxd[j])
                {
                    s++;
                }
            maxa[i] = max(maxa[i],a[i][j]);
            maxt[j] = max(maxt[j],a[i][j]);
        }
    }
    printf("%d",s);
    return 0;
}
