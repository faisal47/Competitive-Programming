#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define FOR_0(i,n) for(i=0;i<n;i++)
#define FOR_1(i,n) for(i=1;i<=n;i++)
#define clr(a) a.clear()
#define pb push_back
#define vec_ vector
#define eps 1E-7
#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define scch(a) scanf("%c",&a)
#define scll1(a) scanf("%lld",&a)
#define scll2(a,b) scanf("%lld %lld",&a,&b)
#define scll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sci1(a) scanf("%d",&a)
#define sci2(a,b) scanf("%d %d",&a,&b)
#define sci3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define scd1(a) scanf("%lf",&a)
#define scd2(a,b) scanf("%lf %lf",&a,&b)
#define scd3(a,b,c) scanf("%lf %lf %lf",&a,&b,&c)
#define sz
using namespace std;


class ProfitCalculator {
public:
int percent(vector <string> items) {

}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	ProfitCalculator *obj;
	int answer;
	obj = new ProfitCalculator();
	clock_t startTime = clock();
	answer = obj->percent(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	vector <string> p0;
	int p1;
	
	{
	// ----- test 0 -----
	string t0[] = {"012.99 008.73","099.99 050.00","123.45 101.07"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 32;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"000.00 049.99","999.99 936.22","033.99 025.64","249.99 211.87"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 4;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"822.77 704.86","829.42 355.45","887.18 949.38"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 20;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"612.72 941.34","576.46 182.66","787.41 524.70","637.96 333.23","345.01 219.69","567.22 104.77","673.02 885.77"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 23;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"811.22 275.32","433.89 006.48","141.28 967.41","344.47 786.23","897.47 860.61","007.42 559.29","255.72 460.00","419.35 931.19","419.25 490.52","199.78 114.44","505.63 276.58","720.96 735.00","719.90 824.46","816.58 195.94","498.68 453.05","399.48 921.39","930.88 017.63","422.20 075.39","380.22 917.27","630.83 995.87","821.07 126.87","715.73 985.62","246.23 134.64","168.28 550.33","707.28 046.72","117.76 281.87","595.43 410.45","345.28 532.42","554.24 264.34","195.73 814.87","131.98 041.28","595.13 939.47","576.04 107.70","716.00 404.75","524.24 029.96","673.49 070.97","288.09 849.43","616.34 236.34","401.96 316.33","371.18 014.27","809.63 508.33","375.68 290.84","334.66 477.89","689.54 526.35","084.77 316.51","304.76 015.91","460.63 636.56","357.84 436.20","752.24 047.64","922.10 573.12"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 10;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
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
