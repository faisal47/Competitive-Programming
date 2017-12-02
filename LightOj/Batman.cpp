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
#define mt 55
using namespace std;
string a,b,c;

int dp[mt][mt][mt];

int solve(int i,int j,int k)
{
    if(sz(a)==i || sz(b)==j || sz(c)==k)return 0;
    int &ret=dp[i][j][k];
    if(ret!=-1)return ret;
    if(a[i]==b[j] && b[j]==c[k] && c[k]==a[i])
    return ret=1+solve(i+1,j+1,k+1);
    return ret=max(solve(i+1,j,k),max(solve(i,j+1,k),solve(i,j,k+1)));
}

int main ()
{
    int test,t=1;
    cin>>test;
    while(test--)
    {
        cin>>a>>b>>c;
        ms(dp,-1);
        printf("Case %d: %d\n",t++,solve(0,0,0));
    }
    return 0;
}

