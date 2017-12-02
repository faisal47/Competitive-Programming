#include <bits/stdc++.h>

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
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
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

#define mt
#define mod

int ache[130],lagbe[130];

int main ()
{
    cffi;
    int i,j;

    string arr1,arr2;
    cin>>arr1>>arr2;

    for(i=0; i<sz(arr2); i++)
        ache[arr2[i]]++;


    for(i=0; i<sz(arr1); i++)
        lagbe[arr1[i]]++;

    int ans1,ans2;
    ans1=ans2=0;

    for(i='a'; i<='z'; i++)
    {
        if(lagbe[i] <= ache[i])
        {
            ans1+=lagbe[i];
            ache[i]-=lagbe[i];
            lagbe[i]=0;
        }
        else
        {
            ans1+=ache[i];
            lagbe[i]-=ache[i];
            ache[i]=0;
        }
    }

    for(i='A'; i<='Z'; i++)
    {
        if(lagbe[i] <= ache[i])
        {
            ans1+=lagbe[i];
            ache[i]-=lagbe[i];
            lagbe[i]=0;
        }
        else
        {
            ans1+=ache[i];
            lagbe[i]-=ache[i];
            ache[i]=0;
        }
    }
    int k;
    for(i='a'; i<='z'; i++)
    {
        j=i-'a';
        k=j+'A';
//            deb((char)i);
            if(lagbe[i] <= ache[k])
            {
                ans2+=lagbe[i];
                ache[k]-=lagbe[i];
                lagbe[i]=0;
            }
            else
            {
                ans2+=ache[k];
                lagbe[i]-=ache[k];
                ache[k]=0;
            }
    }


    for(i='A'; i<='Z'; i++)
    {
        j=i-'A';
        k=j+'a';
//            deb((char)i);
            if(lagbe[i] <= ache[k])
            {
                ans2+=lagbe[i];
                ache[k]-=lagbe[i];
                lagbe[i]=0;
            }
            else
            {
                ans2+=ache[k];
                lagbe[i]-=ache[k];
                ache[k]=0;
            }
    }

    deb(ans1,ans2);

    return 0;
}