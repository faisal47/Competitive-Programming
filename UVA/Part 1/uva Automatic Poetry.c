#include <stdio.h>
#include <string.h>
int main ()
{
    char z,arr1[105],arr2[105],arr3[105],arr4[105],arr5[105],arr6[105];
    int len1,len2,t,i,j,flag,c1,c2,c3,c4,k;
    scanf("%d%c",&t,&z);
    for(i=0;i<t;i++)
    {
        gets(arr1);
        gets(arr2);
        flag=0;c1=0,c2=0,c3=0,c4=0;
        len1=strlen(arr1);
        len2=strlen(arr2);
        for(j=0;j<len1;j++)
        {
            if(arr1[j]=='<'&&flag==0)
            {
                flag+=1;
                continue;
            }
            if(flag==1)
            {
                if(arr1[j]=='>')
                flag+=1;
                else
                arr3[c1++]=arr1[j];
            }
            if(flag==2&&arr1[j]!='<')
            arr5[c2++]=arr1[j];
            if(arr1[j]=='<'&&flag==2)
            flag+=1;
            if(flag==3)
            {
                if(arr1[j]=='>')
                {
                    flag+=1;
                    continue;
                }
                else
                arr4[c3++]=arr1[j];
            }
            if(flag==4)
            arr6[c4++]=arr1[j];
        }
        arr3[c1]='\0';arr5[c2]='\0';arr4[c3]='\0';arr6[c4]='\0';
        for(j=0;j<len1;j++)
        {
            if(arr1[j]!='<'&&arr1[j]!='>')
            printf("%c",arr1[j]);
        }
        printf("\n");
        for(j=0;j<len2;j++)
        {
            if(arr2[j]=='.'&&arr2[j+1]=='.'&&arr2[j+2]=='.')
            {
                len1=strlen(arr4);
                for(k=1;k<len1;k++)
                printf("%c",arr4[k]);
                len1=strlen(arr5);
                for(k=1;k<len1;k++)
                printf("%c",arr5[k]);
                printf("%s%s",arr3,arr6);
                break;
            }
            else
            printf("%c",arr2[j]);
        }
        printf("\n");
    }
    return 0;
}