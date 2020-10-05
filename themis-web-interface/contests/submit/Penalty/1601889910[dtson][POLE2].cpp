#include <bits/stdc++.h>;

using namespace std;
int n,d,c[5000],h[5000];
int main()
{
   freopen("pole2.inp","r",stdin);
   freopen("pole2.out","w",stdout);
   cin>>n>>d;
   for(int i=1;i<n;i++) cin>>c[i];
   for(int i=1;i<=n;i++) cin>>h[i];
   h[0]=h[1];

   long long s=0;
   for(int i=1;i<n;i++)
   {
       while(abs(h[i]-h[i+1]) > d)
       {
           if(h[i]>h[i+1]) h[i+1]++;
           else h[i]++;
       }

       int hi=1;
       if(i==1)
       {
           while((hi*hi) + abs(h[i]+hi-h[i+1])*c[i] < abs(h[i]-h[i+1])*c[i])
           {
               h[i]++;
               hi++;
           }
           hi--;
       }
       else
       {
           while((hi*hi) + abs(h[i]+1-h[i+1])*c[i] + abs(h[i-1]-h[i]-1)*c[i-1] < abs(h[i]-h[i+1])*c[i] + abs(h[i-1]-h[i])*c[i-1] +(hi-1)*(hi-1))
           {
            h[i]++;
            hi++;
           }
           hi--;
       }
       s=s+(hi*hi);
   }

   for(int i=1;i<n;i++) s=s +abs(h[i]-h[i+1])*c[i];
   cout<<s;
   return 0;
}
