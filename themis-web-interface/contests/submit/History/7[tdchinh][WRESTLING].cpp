#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr) ; cout.tie(nullptr);
#define ft fisrt
#define sc second
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define endl '\n'
using namespace std;
const int N = 500001;
int n,a[N],b[N],dem[N],u,maxz,k,truoc[N],c[N];
int binarySearch(int arr[], int l, int r, int x)
{
  if (r >= l)
  {
    int mid = l + (r - l) / 2;
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
    freopen("WRESTLING.INP","r",stdin);
    freopen("WRESTLING.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];
    FOR(i,1,n) c[i] = i;
    FOR(i,1,n)
    {
        k = binarySearch(c,1,n,a[i]);
        truoc[k] = i;
    }
    FOR(i,1,n)
    {
        k = binarySearch(c,1,n,b[i]);
        if (truoc[k] >= i)
        {
            dem[n-(truoc[k]-i)]++;
        }
        else
            dem[i-truoc[k]]++;
    }
    FOR(i,1,n)
    {
        if (maxz < dem[i])
        {
            maxz = dem[i];
            u = i;
        }
    }
    if (u != n)
    cout << u << " " << maxz;
    else
        cout << 0 << " " << maxz;
    return 0;
}
