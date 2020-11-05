#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,t,d,a[50001],s;
int main()
{
    FastIO;
    freopen("DIVSEQ.INP","r",stdin);
    freopen("DIVSEQ.OUT","w",stdout);
    cin >> t;
    for (int l = 1; l <= t; l++)
    {
        cin >> d >> n;
        s = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            a[i] = a[i-1]+a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0 ; j < i; j++)
            {
                if ((a[i]-a[j]) % d == 0)
                    s++;
            }
        }
        cout << s << endl;
    }

    return 0;
}
