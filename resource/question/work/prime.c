/*
TASK: prime.c
LANG: C
AUTHOR: Chirapot Vuthipraphan
CENTER: Samsen
*/

#include <stdio.h>
#include <math.h>

main()
{
    int i,n,pos=1,num=3;
    scanf("%d",&n);
    int prime[n];
    for(i=0;i<n;i++) prime[i]=0;
    prime[0]=2;
    while(prime[n-1]==0)
    {
        for(i=0;i<pos;i++)
        {
            if(num%prime[i]==0) break;
            if(pow(prime[i],2)>num)
            {
                prime[pos]=num;
                pos=pos+1;
                break;
            }
        }
        num=num+2;
    }
    printf("%d",prime[n-1]);
}
