#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
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
#define allr(a) a.rbegin(),a.rend()
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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define mt 7000
#define mod

int three[10];

void init()
{
    int i;
    three[0] = 1;
    for(i=1; i<10; i++)
        three[i] = 3 * three[i-1];
}

int get_bit(int mask, int pos)
{
    return (mask / three[pos]) % 3;
}

int set_bit(int mask, int pos, int bit)
{
    int tmp =(mask / three[pos]) % 3;
    mask -= tmp * three[pos];
    mask += bit * three[pos];
    return mask;
}

int dp[110][(mt)+10];

int s,m,n;
vec_<int>v[110];

int solve(int tpos,int mask)
{
    int i;
    bool f=0;
    for(i=0; i<s; i++)
        if(get_bit(mask,i) < 2)
        {
            f=1;
            break;
        }

    if(!f)
        return 0;

    if(tpos >= n)
        return inf;

    int &ret = dp[tpos][mask];

    if(ret != -1)
        return ret;
    ret=inf;

    int cost=v[tpos][0],j,nb,tmask;
    for(i=1; i<sz(v[tpos]); i++)
    {
        j=v[tpos][i];
        nb=get_bit(mask,j);
        if(nb < 2)
        {
            tmask=mask;
            for(i=1; i<sz(v[tpos]); i++)
            {
                j=v[tpos][i];
                nb=get_bit(mask,j);
                if(nb < 2)
                {
                    tmask=set_bit(tmask,j,nb+1);
                }
            }
            ret=min(ret,cost+solve(tpos+1,tmask));
            break;
        }
    }

    ret=min(ret,solve(tpos+1,mask));

    return ret;
}

char arr1[100010];
string arr;

int main ()
{
    int i,j,ans,nb,nmask;

    while(sci3(s,m,n)==3 && s)
    {
        init();
        nmask=0;
        ms(dp,-1);
        getchar();
        ans=0;
        while(m--)
        {
//            deb("hola");
            gets(arr1);
//            puts(arr1);
            arr=arr1;
//            deb(arr);
            stringstream ss(arr);
            ss>>j;
            ans+=j;
            while(ss>>j)
            {
//                deb(j);
                nb=get_bit(nmask,j-1);
                if(nb < 2)
                {
                    nmask=set_bit(nmask,j-1,nb+1);
                }
            }
        }

        for(i=0; i<n; i++)
            {
                clr(v[i]);
                gets(arr1);
                arr=arr1;
                stringstream ss(arr);
                ss>>j;
                v[i].pb(j);
                while(ss>>j)
                {
                    v[i].pb(j-1);
                }
            }

        printf("%d\n",ans+solve(0,nmask));
    }

    return 0;
}

