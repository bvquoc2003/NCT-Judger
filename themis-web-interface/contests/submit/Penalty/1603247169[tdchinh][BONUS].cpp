#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,k,a[100001],s;
int main()
{
    FastIO;
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    cin >> n >> k;
    for (int i =1 ; i <= n; i++)
    {
        cin >> a[i];
        s = s + a[i];
    }
    k = k % s;
    for (int i = 1; i <= n; i++)
    {
        if (k - a[i] >= 0)
            k = k - a[i];
        else
            break;
    }
    cout << k;
    return 0;
}
