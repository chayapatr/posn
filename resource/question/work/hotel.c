/*
TASK: hotel
LANG: C
AUTHOR: Chirapot Vuthipraphan
CENTER: Samsen
*/

#include <stdio.h>

main()
{
    long long n,sum=0;
    scanf("%lld",&n);
    while(n>0)
    {
        if(n%15>=9) n=n-n%15+15;
        sum=(n-n%15)*200;
        n=n%15;
        if(n==0) break;
        if(n%5==4) n++;
        sum=sum+(n-n%5)*300;
        n=n%5;
        if(n==0) break;
        sum=sum+(n-n%2)*400;
        n=n%2;
        if(n==0) break;
        sum=sum+500;
        break;
    }
    printf("%lld",sum);
}
