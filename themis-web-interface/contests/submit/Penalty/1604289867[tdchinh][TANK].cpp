#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr) ; cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long m,n,a[100005],b[100005];
int main()
{
    FastIO;
    freopen("TANK.INP","r",stdin);
    freopen("TANK.OUT","w",stdout);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i]  = a[i] + a[i-1];
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (a[j] - a[j-i] < m)
                break;
            if (j == n)
            {
                cout << i;
                exit(0);
            }
        }
    }
    return 0;
}
