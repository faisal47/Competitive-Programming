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
#include <assert.h>
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
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
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
#define deb1(a) cout<<a<<endl;
#define deb2(a,b) cout<<a<<" "<<b<<endl
#define deb3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

///***************************************************** ekhon kamer kam ********************************************************************///

#define mt 1010

struct maan1
{
    int s,dam,ki;
};

vec_<maan1>v;

vec_<int>ans[mt];

bool comp(maan1 a,maan1 b)
{
    if(a.ki==b.ki)
        return a.dam>b.dam;

    return a.ki<b.ki;
}

int main ()
{
    int n,k,i,a,b;


    cin>>n>>k;

    for(i=1; i<=n; i++)
    {
        cin>>a>>b;
        v.pb({i,a,b});
    }

    sort(all(v),comp);
    int c=0;

    dd mot=0.;

    for(i=1; i<k; i++)
    {
        if(v[c].ki==1)
            mot+=((dd)v[c].dam)/2.;
        else
            mot+=(dd)v[c].dam;

        ans[i].pb(v[c].s);
        c++;
    }

    int mini=inf;
    bool flag=0;

    while(c<sz(v))
    {
        mot+=(dd)v[c].dam;

        if(v[c].ki==1)
            flag=1;

        mini=min(mini,v[c].dam);

        ans[k].pb(v[c++].s);
    }

    if(flag)
    mot-=((dd)mini)/2.;

    pf("%.1lf\n",mot);

    int j;

    for(i=1;i<=k;i++)
    {
        cout<<sz(ans[i]);
        for(j=0;j<sz(ans[i]);j++)
            cout<<" "<<ans[i][j];

        cout<<endl;
    }

    return 0;
}