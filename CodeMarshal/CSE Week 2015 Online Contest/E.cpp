#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n)==1)
    {
      if(n<9) printf("0\n");
	else if(n == 9) printf("8\n");
	else
	{
		printf("72");
		for(int i=11; i<=n; i++)
		{
			printf("0");
		}
		printf("\n");
	}
    }
	return 0;
}
