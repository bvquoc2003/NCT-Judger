#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl "\n"
#define INT long long
using namespace std;
INT n,a[100001],b[100001],k,t1,t2,minz = LONG_MAX,z1,z2;
int binarySearch(INT arr[], INT l, INT r, INT x)
{
  if (r >= l) {
    int mid = l + (r - l) / 2;
    k = mid + 1;
    if (arr[mid] == x)
      return mid;
    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);
    return binarySearch(arr, mid + 1, r, x);
  }
  return -1;
}
int main()
{
    FastIO;
    freopen("GAME.INP","r",stdin);
    freopen("GAME.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] < 0)
                z1 = 1;
            if (a[i] > 0)
                z2 = 1;
        }
    for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
            if (b[i] < 0)
                z1 = 1;
            if (b[i] > 0)
                z2 = 1;
        }
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    if ((z1 == 1 && z2 == 0) || (z1 == 0 && z2 == 1))
    {
    minz = min(abs(a[1]+b[1]),abs(a[n]+b[n]));
    cout << minz;
    exit(0);
    }
    for (int i = 1; i <= n; i++)
        if (a[i] >= 0)
        {
        t1 = i;
        break;
        }
    for (int i = 1; i <= n; i++)
        if (b[i] >= 0)
        {
        t2 = i;
        break;
        }
    for (int i = 1; i <= t1-1; i++)
    {
        binarySearch(b,t2,n,-a[i]);
        minz = min(minz, abs(a[i]+b[k]));
        minz = min(minz, abs(a[i]+b[k-1]));
    }
    for (int i = t1; i <= n; i++)
    {
        binarySearch(b,1,t2-1,-a[i]);
        minz = min(minz, abs(a[i]+b[k]));
        minz = min(minz, abs(a[i]+b[k-1]));
    }
    cout << minz;
    return 0;
}
