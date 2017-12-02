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
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define sz(a) a.size()
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


class LightSwitchingPuzzle
{
public:
    int minFlips(string arr)
    {
        int ans=0,cnt,en,cnta,i;
        bool flag;
        while(1)
        {
            flag=0;
            for(i=0; i<sz(arr); i++)
            {
                if(arr[i]=='Y')
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                break;

            cnta=1;
            int j;
            for(i=1; i<=sz(arr); i++)
            {
                if(arr[i-1]=='Y')
                {
                    cnt=0;
                    for(j=i; j<=sz(arr); j+=i)
                        if(arr[j-1]=='Y')
                            cnt++;


                    if(cnt >= cnta)
                    {
                        cnta=cnt;
                        en=i;
                    }
                }
            }
            /// YYYN YYYN YYYN YYNY YYYN
//            deb(en);
//            deb(arr);
            for(i=en;i<=sz(arr);i+=en)
            {
                if(arr[i-1]=='Y')
                    arr[i-1]='N';
                else
                    arr[i-1]='Y';
            }
            ans++;
//            if(ans==3)
//                break;

        }

        return ans;
    }
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1)
{
    cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
    cout << "]" << endl;
    LightSwitchingPuzzle *obj;
    int answer;
    obj = new LightSwitchingPuzzle();
    clock_t startTime = clock();
    answer = obj->minFlips(p0);
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
        res = answer == p1;
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

    string p0;
    int p1;

    {
        // ----- test 0 -----
        p0 = "YYYYYY";
        p1 = 1;
        all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = "YNYNYNYNY";
        p1 = 2;
        all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = "NNNNNNNNNN";
        p1 = 0;
        all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = "YYYNYYYNYYYNYYNYYYYN";
        p1 = 4;
        all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = "NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY";
        p1 = 12;
        all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
// PROBLEM STATEMENT
//
// Leo has N lights in a row.
// The lights are numbered 1 through N.
// Each light is either on or off.
//
//
//
// Leo wants to turn all the lights off.
// He has N switches he may use.
// The switches are also numbered 1 through N.
// For each i, switch number i toggles the state of all lights whose numbers are multiples of i.
// (For example, switch 3 will toggle the state of light 3, light 6, light 9, and so on.)
//
//
//
// You are given the current state of all lights as a string state with N characters.
// For each valid i, state[i] is either 'Y' (meaning that light i+1 is currently on) or 'N' (meaning that the light is off).
// Determine the smallest number of switches Leo needs to press in order to turn off all the lights.
// If there is no way to turn off all the lights, return -1 instead.
//
//
// DEFINITION
// Class:LightSwitchingPuzzle
// Method:minFlips
// Parameters:string
// Returns:int
// Method signature:int minFlips(string state)
//
//
// CONSTRAINTS
// -state will contain between 1 and 1000 characters, inclusive.
// -Each character of state will be either 'Y' or 'N'.
//
//
// EXAMPLES
//
// 0)
// "YYYYYY"
//
// Returns: 1
//
// We can turn off all the lights by pressing switch 1.
//
// 1)
// "YNYNYNYNY"
//
// Returns: 2
//
//
// We cannot turn these lights off in a single step.
// It can be done in two steps.
// One possible solution looks as follows:
// First, press the second switch.
// This will toggle lights with numbers 2, 4, 6, and 8.
// The state of the lights after this change will be "YYYYYYYYY".
// Next, press the first switch to toggle all lightbulbs.
//
//
// 2)
// "NNNNNNNNNN"
//
// Returns: 0
//
// All the lights are already off.
//
// 3)
// "YYYNYYYNYYYNYYNYYYYN"
//
// Returns: 4
//
//
//
// 4)
// "NYNNYNNNYNNNNYNNNNNYNNNNNNYNNNNNNNY"
//
// Returns: 12
//
//
//
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
