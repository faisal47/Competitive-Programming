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

#define mt
#define mod

dd dp[255][255];
vec_<int>arr;
int n;

dd solve(int pos,int koyta)
{
    if(pos == 0 || koyta==n)
        return 0;
    dd &ret=dp[pos][koyta],cnt;
    int i;
    if(ret != -1.)
        return ret;
    ret=0;
    for(i=0;i<pos;i++)
        ret+=(dd)(arr[i])+solve(i,koyta+1);
    cnt=n-koyta;
    ret/=cnt;
    return ret;
}

class RandomPancakeStack
{
public:
    double expectedDeliciousness(vector <int> d)
    {
        arr=d;
        int i,j;
        n=sz(arr);
        for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=-1.;
        return solve(n,0);
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, double p1)
{
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}";
    cout << "]" << endl;
    RandomPancakeStack *obj;
    double answer;
    obj = new RandomPancakeStack();
    clock_t startTime = clock();
    answer = obj->expectedDeliciousness(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer)
    {
        cout << "Desired answer:" << endl;
        cout << "\t" << p1 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer)
    {
        res = fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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

    vector <int> p0;
    double p1;

    {
        // ----- test 0 -----
        int t0[] = {1,1,1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1.6666666666666667;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {3,6,10,9,2};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 9.891666666666667;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {10,9,8,7,6,5,4,3,2,1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 10.999999724426809;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {1,2,3,4,5,6,7,8,9,10};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 7.901100088183421;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        int t0[] = {2,7,1,8,2,8,1,8,2,8,4,5,90,4,5,2,3,5,60,2,8,74,7,1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 19.368705050402465;
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        int t0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        p1 = 1.718281828459045;
        all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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