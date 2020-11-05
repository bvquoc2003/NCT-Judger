#include <bits/stdc++.h>
#define int long long

using namespace std;

int n,m;
int f[205][205][205], kq[205][205][205];
string s;
char a[100000];
int vt[10000];
int d[1005][1000];
int xuli(int i, int j, int k) {
    int t, x1, x2, nho;
    if (i>j) return k*k;
    if (i==j) return (k+1)*(k+1);
    if (kq[i][j][k]==1) return f[i][j][k];

    int res=0;

    nho=0;
    for (int t=i+1;t<=j;t++) {
        if (a[t]!=a[i]) {
            res=(t-i+k)*(t-i+k)+xuli(t,j,0);
            break;
        }
    }
    t=d[i][a[i]];
    while (t>0 && t<=j) {
        res=max(res,xuli(i+1,t-1,0)+xuli(t,j,k+1));
        t=d[t][a[t]];
    }
    kq[i][j][k]=1;
    f[i][j][k]=res;
    return res;
}
int32_t main()
{
    freopen("CUTSEQ.INP","r",stdin);
    freopen("CUTSEQ.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=n;i>=1;i--) {
        for (int j='0';j<='9';j++)
            d[i][j]=vt[j];
        vt[a[i]]=i;
    }
    int ans=xuli(1,n,0);
    cout<<ans;
    return 0;
}

