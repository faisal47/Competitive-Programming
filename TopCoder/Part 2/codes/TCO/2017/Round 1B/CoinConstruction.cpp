#include <bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define pil pair<int,ll>
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
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repa(i,n) for(auto i:n)
using namespace std;

template<class T1> void deb(T1 e){cout<<e<<endl;}
template<class T1,class T2> void deb(T1 e1,T2 e2){cout<<e1<<" "<<e2<<endl;}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3){cout<<e1<<" "<<e2<<" "<<e3<<endl;}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6){cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;}
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

vec_<int>solve(int num){

    vec_<int>ret;
    if(num == 2){
        ret.pb(1);
        return ret;
    }
    while(num > 1)
    {
        for(int i=2;i<=20;i++){
            if(num%i==0){
                num/=i;
                ret.pb(i);
                break;
            }
        }
    }
    vec_<int>ret2;
    int mot=1;
    repa(b,ret){
        rep(i,b-1)
        ret2.pb(mot);
        mot=(mot*b)+1;
    }
    return ret2;
}

class CoinConstruction {
public:
	vector <int> construct(int k) {
		return solve(k+1);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	CoinConstruction *obj;
	vector <int> answer;
	obj = new CoinConstruction();
	clock_t startTime = clock();
	answer = obj->construct(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	int p0;
	vector <int> p1;

	{
	// ----- test 0 -----
	p0 = 6;
	int t1[] = {3,4,7};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	p0 = 26;
	int t1[] = {1,1,10,10,100,100};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	p0 = 7;
	int t1[] = {1,1,1,1,1,1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	p0 = 1;
	int t1[] = {999999999};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING




//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
