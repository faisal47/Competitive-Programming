#include <stdio.h>
#include <string.h>
char arr[100005],arr1[100005];
int main ()
{
    int len,i,c,j,flag;
    while(gets(arr))
    {
        c=0;
        len=strlen(arr);
        for(i=len-1;i>=0;i--)
        {
            if(arr[i]=='[')
            {
                for(j=i+1;j<len;j++)
                {
                    if(arr[j]=='['||arr[j]==']')
                    break;
                    arr1[c++]=arr[j];
                }
            }
        }
        flag=0;
        arr1[c]='\0';
        printf("%s",arr1);
        for(i=0;i<len;i++)
        {
            if(arr[i]=='[')
            flag=1;
            if(flag==0)
            {
                if(arr[i]!=']')
                printf("%c",arr[i]);
            }
            if(arr[i]==']')
            flag=0;
        }
       printf("\n");
    }
    return 0;
}