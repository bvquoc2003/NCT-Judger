#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
long long n,t,k,mid,c,s,r,q,z,a[10000007];
int tknp(long long arr[], long long l, long long r, long long x) {
  if (r >= l) {
    mid = l + (r - l) / 2;
             c = mid;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] > x)
      return tknp(arr, l, mid - 1, x);
    return tknp(arr, mid + 1, r, x);
  }
  if (a[c] < x)
  return c;
  else
    return c-1;
}
int main()
{
    FastIO;
    freopen("CANDIES.INP","r",stdin);
    freopen("CANDIES.OUT","w",stdout);
    cin >> t;
    z = 2;
    a[1] = 1;
    a[2] = 1;
    while (a[z] <= 100000000000000)
    {
        z++;
        a[z] = a[z-1] + a[z-2];
    }
    while (t > 0)
    {
        t--;
        cin >> n >> k;
        r = 0;
        if (k > 10)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            q = i;
            s = 0;
              while (q > 0)
              {
                  s++;
                  q = q - a[tknp(a,1,z,q)];
              }
            if (s >= k)
                r += s;
        }
        cout << r << endl;
    }
    return 0;
}
