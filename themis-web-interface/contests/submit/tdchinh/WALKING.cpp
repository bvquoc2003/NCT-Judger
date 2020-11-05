#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
int n,t[100005],v[100005],a[10005][10005],k,b[10005],r,maxz;
long long l;
int kiemtra(int a, int b, int c, int d)
{
    int z,x;
            if (l%b == 0)
            {
                z = l / b;
            }
            else
                z = l / b + 1;
            if (l%d == 0)
            {
                x = l / d;
            }
            else
                x = l / d + 1;
            if (a < c && z + a > x + c)
                   return 1;
    return 0;
}
int main()
{
    FastIO;
    freopen("WALKING.INP","r",stdin);
    freopen("WALKING.OUT","w",stdout);
    cin >> l >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i] >> v[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (kiemtra(t[i],v[i],t[j],v[j]) == 1 || kiemtra(t[j],v[j],t[i],v[i]) == 1)
                a[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        k = 1;
        r = 0;
        b[k] = i;
        for (int j = i+1; j <= n; j++)
            {
                if (a[i][j] == 1)
                {
                    k++;
                    b[k] = j;
                }
            }
        for (int j = 1; j <= k; j++)
        {
            for (int q = j+1; q <= k ; q++)
            {
                if (a[b[j]][b[q]] != 1)
                    r = 1;
            }
        }
        if (r == 0 && maxz < k)
        maxz = k;
    }
    cout << maxz;
    return 0;
}
