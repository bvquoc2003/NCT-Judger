#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,m,k,a[10],z,s;
long long dequy(long long a[],long long t)
{
    for (int i = a[t]; i >= 0; i--)
    {
        z = z + i;
        if (t < n && z > k*9)
            if (t != 1)
            return 0;
        if (t < n)
        dequy(a,t+1);
        if (z % 9 == 0 && z <= m && t == n)
            {
                s++;
            }
        z = z - i;
    }
}
int main()
{
    FastIO;
    freopen("vuive9.inp","r",stdin);
    freopen("vuive9.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
            k = m / 9;
    dequy(a,1);
    cout << s;
    return 0;
}
