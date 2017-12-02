#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sort_n(a) sort(a.begin(),a.end())
#define sort_m(a) sort(a.begin(),a.end(),comp)
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define pri1(a) printf("%d ",a)
#define pri2(a,b) printf("%d %d ",a,b)
#define prll1(a) printf("%I64d ",a)
#define prll2(a,b) printf("%I64d %I64d ",a,b)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define mt 200000+20
using namespace std;

int f[mt],c,co[mt],ans;
string pattern;
const int mod=10007;
void kmp()
{
    int k;
    f[0]=k=0;
    int i;
    co[0]=1;
    for(i=1; i<sz(pattern); i++)
    {
        co[i]=1;
        while(k>0 && pattern[i]!=pattern[k])
            k=f[k-1];
        if(pattern[i]==pattern[k])
            k++;
        f[i]=k;
    }

    for(i=sz(pattern)-1;i>0;i--)
    if(f[i])
    {
        co[f[i]-1]=(co[f[i]-1]+co[i])%mod;
    }

    ans=0;

    for(i=0;i<sz(pattern);i++)
    {
       // cout<<i<<" "<<f[i]<<" "<<co[i]<<endl;
      // cout<<co[i]<<endl;
        ans=(ans+co[i])%mod;
    }
    cout<<ans<<endl;
}

int main ()
{
    int i,test,n;
    sci1(test);
    while(test--)
    {
        cin>>n>>pattern;
        kmp();
    }
    return 0;
}



