#include <iostream>
#include <stdio.h>
using namespace std;
unsigned long long arr[1000003];
int main ()
{
    unsigned long long i,j,k,l,a,b,c,d,e,flag;
    arr[2]=1;
    for(i=3; i<1000002; i+=2)
    {
        if(arr[i]==0)
        {
            arr[i]=1;
            for(j=i+i; j<1000002; j+=i)
                arr[j]=3;
        }
    }
    while((scanf("%llu",&a))==1)
    {
        if(a==0)
            break;
            k=0;
        flag=0;
        c=a/2;
        for(i=2; i<=c; i++)
        {
            b=i;
            if(arr[b]==1)
            {
                d=a-b;
                if(arr[d]==1)
                {
                    ++k;
                    flag=1;
                }
            }
        }
        if(flag==0)
            printf("0\n");
        else
            cout<<k<<endl;
    }
    return 0;
}
