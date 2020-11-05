#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,a[1000001],maxz,z,k;
int main()
{
    FastIO;
    freopen("SHOPSIGN.INP","r",stdin);
    freopen("SHOPSIGN.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        z = i+1;
        k = 0;
        while (a[z] >= a[i] && k < a[i])
        {
            k++;
            z++;
        }
        z = i - 1;
        while (a[z] >= a[i] && k < a[i])
        {
            k++;
            z++;
        }
        if (k == a[i] && maxz < a[i])
            maxz = a[i];
    }
    cout << maxz;
    return 0;
}
