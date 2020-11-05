#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,a,b,t,k;
int uoc(long long n)
{
    int s = 0;
    for (int i = 1; i <= sqrt(n);i++)
    {
        if (n % i == 0)
        {
            int j = n/i;
            s++;
            if (i != j)
                s++;
        }
    }
    return s;
}
int main()
{
    FastIO;
    freopen("DMT.INP","r",stdin);
    freopen("DMT.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        if (a % 3 == 1)
            a = a + 2;
        if (a % 3 == 2)
            a++;
        for (int j = a; j <= b; j = j + 3)
        {
            if (uoc(j) == 9)
                k++;
        }
        cout << k << endl;
    }
    return 0;
}
