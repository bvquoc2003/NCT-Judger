#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long k,s,i,t;
int main()
{
    FastIO;
    freopen("SQUARE.INP","r",stdin);
    freopen("SQUARE.OUT","w",stdout);
    cin >> k;
    for (i = 1; i*i <= 2e12; i++)
    {
        if (k >= 0)
        {t = sqrt(k);
        if (t*t == k)
        {
            cout << t << endl;
            exit(0);
        }
        }
        k = k - (i-1)*(i-1);
        k = k + i*i;
    }
    cout << "none";
    return 0;
}
