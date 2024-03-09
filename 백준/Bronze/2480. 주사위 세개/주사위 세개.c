#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a==b&&b==c&&c==a)
    {
        printf("%d",a*1000+10000);
    }
    else if (a==b)
    {
        printf("%d",b*100+1000);
    }
    else if (b==c)
    {
        printf("%d",b*100+1000);
    }
    else if (c==a)
    {
        printf("%d",c*100+1000);
    }
    
    else
    {
        if(a>b&&a>c)
        {
            printf("%d",100*a);
        }
            
        else if(b>c&&b>a)
        {
            printf("%d",100*b);
        }
            
        else 
        {
            printf("%d",100*c);
        }
    }
    return 0;
}