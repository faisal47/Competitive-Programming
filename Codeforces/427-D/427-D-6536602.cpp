#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cctype>
#include <set>
#include <bitset>
#include <algorithm>
#include <list>
#include <vector>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair< ll, ll > pall;
#define inf 1<<28

#define PI (2.0*acos(0))
#define ERR 1e-5
#define mem(a,b) memset(a,b,sizeof a)
#define pb push_back
#define popb pop_back
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define sz(x) (int)x.size()
#define oo (1<<25)
#define FOREACH(it,x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define Contains(X,item)        ((X).find(item) != (X).end())
#define popc(i) (__builtin_popcountll(i))
#define fs      first
#define sc      second
#define EQ(a,b)     (fabs(a-b)<ERR)
#define mt (2*5000)+20
#define twoL(X) (((ll)(1))<<(X))

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


template<class T> T Abs(T x)
{
    return x > 0 ? x : -x;
}
template<class T> inline T sqr(T x)
{
    return x*x;
}
ll Pow(ll B,ll P)
{
    ll R=1;
    while(P>0)
    {
        if(P%2==1)     R=(R*B);
        P/=2;
        B=(B*B);
    }
    return R;
}
ll BigMod(ll B,ll P,ll M)
{
    ll R=1;    /// (B^P)%M
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

struct SAdata
{
    pii val;
    int pos;
    SAdata() {}
    SAdata(pii x, int y)
    {
        val=x;
        pos=y;
    }
} SADT[mt]; /// temporary Data Structure for building SA
bool comSA(SAdata a, SAdata b)
{
    return a.val<b.val;
}

string input_text;/// Input String for SA to build
int SA[mt],revSA[mt];      /// Found SA and reverse SA
int lcp[mt]; /// longest common prfix array for adjacent suffixes found in SA


/// SA returns the start positions  of the suffixes which are stored in lexicographical order
/// revSA returns for every suffix starting at 0 its position in SA

void buildSA()
{
    for(int i=0; i<sz(input_text); i++) revSA[i]=input_text[i];
    int prv_rank;

    for(int cnt=1; cnt<sz(input_text); cnt*=2)
    {
        for(int i=0; i<sz(input_text); i++)
        {
            SADT[i].pos=i;
            SADT[i].val.fs=revSA[i];
            SADT[i].val.sc= (i+cnt<sz(input_text)) ? revSA[i+cnt] : -1;
        }
        sort(SADT,SADT+sz(input_text),comSA);

        for(int i=0; i<sz(input_text); i++)
        {
            revSA[ SADT[i].pos ]= (i-1>=0 && SADT[i].val==SADT[i-1].val) ? prv_rank : i ;
            prv_rank=revSA[ SADT[i].pos ];
        }
    }
    for(int i=0; i<sz(input_text); i++) SA[revSA[i]]=i;
}

void buildLCP()
{
    int mx_mtch=0,SApos,j;
    for(int i=0; i<sz(input_text); i++)
    {

        SApos=revSA[i];
        if(SApos==0) continue;
        if(mx_mtch>0) mx_mtch--;

        j=SA[SApos-1];

        while( (i+mx_mtch)<sz(input_text) && (j+mx_mtch)<sz(input_text) && input_text[i+mx_mtch]==input_text[j+mx_mtch]  )
            mx_mtch++;

        lcp[SApos]=mx_mtch;
    }
    lcp[0]=0;

    return ;
}

int len1,ans;

bool solve(int l)
{
    int i,j,c1,c2;
    for(i=1; i<sz(input_text); i=j+1)
    {
        c1=c2=0;

        while(i<sz(input_text) && lcp[i]<l)i++;

        if(SA[i-1]<len1)
                c1++;
            else
                c2++;

        for(j=i; j<sz(input_text) && lcp[j]>=l; j++)
        {
            if(SA[j]<len1)
                c1++;
            else
                c2++;
        }

        if(c1==1 && c2==1)
            return 1;
    }

    return 0;
}

int main()
{
//    freopen("cas.txt","r",stdin);
//    freopen("outShakil.txt","w",stdout);

    char arr[mt];
    int cas;
    //scanf("%d",&cas);
    //while(cas--)
    scanf("%s",arr);
    input_text=arr;
    len1=sz(input_text);
    input_text+='#';
    scanf("%s",arr);
    input_text+=arr;
    buildSA();
    buildLCP();
    int i;
    for(i=1; i<=len1; i++)
    {
        if(solve(i))
        {
            cout<<i;
            return 0;
        }
    }

    puts("-1");

    return 0;
}