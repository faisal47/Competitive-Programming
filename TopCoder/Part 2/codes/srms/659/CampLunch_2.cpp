#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pii pair<int,int>
#define pi acos(-1)
#define fs first
#define sc second
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz(a) (int)a.size()
#define ll long long
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
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};

//#define mt 1000000007
#define mod 1000000007

ll dp[17][66000];
vector <string> arr;
int n,m;
ll solve(int r,int mask);
ll gen(int r,int c,int nmask,int nxmask)
{
    if(c==m)
        return solve(r+1,nxmask);

    ll ret=0;
    if(nmask&(1<<c))
        return gen(r,c+1,nmask,nxmask);

    ret=gen(r,c+1,nmask,nxmask);
    if(ret >= mod)
        ret%=mod;

    if(c+1<m && !(nmask & (1<<(c+1))))
        ret=(ret + gen(r,c+2,nmask,nxmask));
    if(ret>=mod)
        ret%=mod;

    int i;
    if(r+1<n)
    {
        for(i=0; i<m; i++)
            if(arr[r+1][i]==arr[r][c])
            {
                ret=(ret + gen(r,c+1,nmask,nxmask|(1<<i)));
                if(ret>=mod)
                    ret%=mod;
                break;
            }
    }

    return ret;
}

ll solve(int r,int mask)
{
    if(r == n)
    {
        if(mask)
            return 0ll;
        return 1ll;
    }
    ll &ret=dp[r][mask];
    if(ret != -1)
        return ret;
    ret=gen(r,0,mask,0);
    return ret;
}

class CampLunch
{
public:
    int count(int N, int M, vector <string> a)
    {
        arr=a;
        n=N;
        m=M;
        ms(dp,-1);
        return (int)solve(0,0);
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <string> p2, bool hasAnswer, int p3)
{
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << "\"" << p2[i] << "\"";
    }
    cout << "}";
    cout << "]" << endl;
    CampLunch *obj;
    int answer;
    obj = new CampLunch();
    clock_t startTime = clock();
    answer = obj->count(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = answer == p3;
    }
    if (!res)
    {
        cout << "DOESN'T MATCH!!!!" << endl;
    }
    else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2)
    {
        cout << "FAIL the timeout" << endl;
        res = false;
    }
    else if (hasAnswer)
    {
        cout << "Match :-)" << endl;
    }
    else
    {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main()
{
    bool all_right;
    all_right = true;

    int p0;
    int p1;
    vector <string> p2;
    int p3;

    {
        // ----- test 0 -----
        p0 = 2;
        p1 = 2;
        string t2[] = {"AB","AB"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 7;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 2;
        p1 = 3;
        string t2[] = {"ABC","ABC"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 22;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 2;
        p1 = 3;
        string t2[] = {"ABC","BAC"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 21;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 1;
        p1 = 1;
        string t2[] = {"A"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 1;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 1;
        p1 = 10;
        string t2[] = {"ABDEFHIGJC"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 89;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        p0 = 16;
        p1 = 16;
        string t2[] = {"ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP"};
        p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
        p3 = 950052677;
        all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    if (all_right)
    {
        cout << "You're a stud (at least on the example cases)!" << endl;
    }
    else
    {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING




//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
