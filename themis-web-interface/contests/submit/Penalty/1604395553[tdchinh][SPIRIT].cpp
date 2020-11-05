#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
int a,b,c,s;
int main()
{
    FastIO;
    freopen("SPIRIT.INP","r",stdin);
    freopen("SPIRIT.OUT","w",stdout);
    cin >> a >> b >> c;
    if (c == 2)
    {
        if (a % 2 == 0)
        {
            a++;
            a = b - a;
            s = 1 + (a+1)/2;
        }
        else
        {
            s = (b-a+1)/2;
        }
        cout << s;
        exit(0);
    }
    if (c % 2 == 0 && c != 2)
    {
        s = (b-a+1)/2;
        cout << s;
        exit(0);
    }
    while (a < b)
    {
        if ((a+2)%c != 0)
            a += 2;
        else
            a+= 1;
        s++;
    }
    cout << s;
    return 0;
}
